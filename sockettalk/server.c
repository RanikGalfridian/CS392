#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include "my.h"
#include "mylist.h"

#define PORT    5555
#define MAXMSG  1024

struct client {
    char* username;
    int fd;
};

struct client* getClient(struct s_node** head, int fd){
    int i;
    int length = count_s_nodes(head[0]);
    for(i = 0; i < length; i++){
        if(((struct client*)elem_at(head[0], i))->fd == fd)
            return (struct client*)elem_at(head[0], i);
    }
    return NULL;
}

void removeClient(struct s_node** head, int fd){
    int i;
    int length = count_s_nodes(head[0]);
    for(i = 0; i < length; i++){
        if(((struct client*)elem_at(head[0], i))->fd == fd){
            remove_node_at(head, i);
        }
    }
}

void sendMessages(struct s_node** head, char* message){
    int i;
    int length = count_s_nodes(head[0]);
    for(i = 0; i < length; i++){
        write(((struct client*)elem_at(head[0], i))->fd, message, my_strlen(message));
    }
}

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sockfd, portno, i, new;
    char buffer[MAXMSG];
    struct sockaddr_in serv_addr;
    fd_set active_fd_set, read_fd_set;
    struct sockaddr_in clientname;
    socklen_t size;
    int nbytes;
    struct s_node** head = (struct s_node**) malloc(sizeof(struct s_node*));
    struct client* newclient;
    char* publicBuffer;

    head[0] = NULL;

    if (argc < 2) {
        my_str("ERROR: No port provided.\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding");
    listen(sockfd,5);

    FD_ZERO (&active_fd_set);
    FD_SET (sockfd, &active_fd_set);

    while (1){
      /* Block until input arrives on one or more active sockets. */
        read_fd_set = active_fd_set;
        if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0){
            perror ("select");
            exit (EXIT_FAILURE);
        }

      /* Service all the sockets with input pending. */
        for (i = 0; i < FD_SETSIZE; ++i){
            if (FD_ISSET (i, &read_fd_set)){
                if (i == sockfd){
                    /* Connection request on original socket. */
                    size = sizeof (clientname);
                    new = accept (sockfd, (struct sockaddr *) &clientname, &size);
                    if (new < 0){
                        perror ("accept");
                        exit (EXIT_FAILURE);
                    }
                    FD_SET (new, &active_fd_set);

                    newclient = (struct client*) malloc(sizeof(struct client));

                    newclient->fd = new;
                    newclient->username = NULL;
                    add_elem((void*) newclient, head);

                }else{
                    /* Data arriving on an already-connected socket. */
                      bzero(buffer, 1024);
                      nbytes = read (i, buffer, MAXMSG);
                      if (nbytes < 0){
                          /* Read error. */
                          perror ("read");
                          exit (EXIT_FAILURE);
                      }else if (nbytes == 0){
                        /* End-of-file. */
                        removeClient(head, i);
                        close(i);
                        FD_CLR(i, &active_fd_set);
                      }
                      else{
                          /* Data read. */
                        if(getClient(head, i)->username == NULL){
                            getClient(head, i)->username = my_strdup(buffer);
                        }else if(my_strncmp(buffer, "/", 1) == 0){

                            if(my_strncmp(buffer, "/nick ", 6) == 0){
                                if(my_strlen(buffer) < 18){
                                    getClient(head, i)->username = my_strdup(&buffer[6]);
                                }
                                if(my_strlen(buffer) == 6 || my_strlen(buffer) == 5){
                                    write(i, "That was an invalid command.", my_strlen("That was an invalid command."));
                                }
                            }else if (my_strncmp(buffer, "/exit", 5) == 0 || my_strncmp(buffer, "/exit ", 6) == 0){
                                removeClient(head, i);
                                close(i);
                                FD_CLR(i, &active_fd_set);
                            }else if (my_strncmp(buffer, "/me ", 4) == 0){
                                publicBuffer = my_strconcat("[", getClient(head, i)->username);
                                publicBuffer = my_strconcat(publicBuffer, "] ");
                                publicBuffer = my_strconcat(publicBuffer, my_strdup(&buffer[4]));
                                sendMessages(head, publicBuffer);
                            }else{
                                write(i, "That was an invalid command.", my_strlen("That was an invalid command."));
                            }
                        }else{
                            publicBuffer = my_strconcat("[", getClient(head, i)->username);
                            publicBuffer = my_strconcat(publicBuffer, "]: ");
                            publicBuffer = my_strconcat(publicBuffer, buffer);
                            sendMessages(head, publicBuffer);
                            bzero(buffer, 1024);
                        }
                    }
                }
            }
        }
    }
    
    return 0; 
}

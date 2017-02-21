#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n, i;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    fd_set active_fd_set, read_fd_set;
    char buffer[1024];

    if (argc < 3) {
       my_str("usage ");
       my_str(argv[0]);
       my_str(" hostname port \n");
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        my_str("ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    my_str("Please enter your username: ");
    bzero(buffer,1024);
    fgets(buffer,1023,stdin);
    if(my_strrfind(buffer, '\n') != NULL){
         *my_strrfind(buffer, '\n') = '\0';
    }
    if(my_strlen(buffer) <= 12){
        n = write(sockfd,buffer,strlen(buffer));
    }else{
        error("ERROR username must be at most 12 characters");
    }

    FD_ZERO(&active_fd_set);
    FD_SET(0, &active_fd_set);
    FD_SET(sockfd, &active_fd_set);
    
    while(1){
        read_fd_set = active_fd_set;
        if(select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0){
            perror("select");
            exit(EXIT_FAILURE);       
        }
        for(i = 0; i < FD_SETSIZE; ++i){
            if(FD_ISSET (i, &read_fd_set)){
                if(i == 0){
                    bzero(buffer, 1024);
                    fgets(buffer, 1024, stdin);
                    if(my_strrfind(buffer, '\n') != NULL){
                        *my_strrfind(buffer, '\n') = '\0';
                    }
                    n = write(sockfd, buffer, strlen(buffer));

                    if(n < 0){
                        error("ERROR writing to socket");
                    }
                    

                    if(my_strncmp(buffer, "/exit", 5) == 0 || my_strncmp(buffer, "/exit ", 6) == 0){
                        close(sockfd);
                        return 0;
                    }
                }

                if(i == sockfd){
                    bzero(buffer, 1024);
                    n = read(sockfd, buffer, 1024);
                    my_str(buffer);
                    my_str("\n");
                    if(n < 0){
                        error("ERROR reading from socket");
                    }
                }
            }
        }
    }
    return 0;
}

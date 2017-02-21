#include "my.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int pipefd[2];
    pid_t cpid;
    pid_t gpid;
    //char buf;
    char* finStr = (char*) malloc(sizeof(char));

   if(argc == 1){
        my_str("Usage: Please provide arguments.\n");
        exit(EXIT_FAILURE);
    }

    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    finStr = my_vect2str(argv);
    
    if((cpid = fork()) == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    } else if(cpid == 0){                 
        close(pipefd[1]);

        my_str("Child: ");
        my_str(finStr);
        my_str("\n");
        
        gpid = fork();
        if(gpid == -1){
            perror("fork");
            exit(EXIT_FAILURE);
        } else if(gpid == 0){
            close(pipefd[1]);
            my_str("Grandchild: ");
            my_str(finStr);
            my_str("\n");

            close(pipefd[0]);
            exit(EXIT_SUCCESS);
        } else {
            close(pipefd[0]);
            exit(EXIT_SUCCESS);
        }
    } else {                       
        close(pipefd[0]);          
        
        my_str("Parent: ");
        my_str(finStr);
        my_str("\n");

        close(pipefd[1]);          
        wait(NULL);                
        exit(EXIT_SUCCESS);
    } 
    return 1;
}

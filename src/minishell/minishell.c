#include "my.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int my_cd(char** args);
int my_help(char** args);
int my_exit(char** args);

char* builtin_str[] = {"cd", "help", "exit"};
int (*builtin_func[])(char**) = {&my_cd, &my_help, &my_exit};

int num_builtins(){
    return sizeof(builtin_str) / sizeof(char*);
}

int my_cd(char** args){
    if(args[1] == NULL){
        my_str("EXPECTED AN ARGUMENT TO \"cd\"\n");
    }else{
        if(chdir(args[1]) != 0){
            perror("shell");
        }
    }
    return 1;
}

int my_help(char** args){

    my_str("This is Zach's shell program\n");
    my_str("You can type in program names and arguments just like the terminal, then hit enter to execute the program.\n");
    my_str("\'cd\', \'help\', and \'exit\' are built in commands\n");

    return 1;
}

int my_exit(char** args){
    return 0;
}

int alive;
pid_t pid;

void ctrlc(int sig){
    if(alive == 1){
        kill(pid, SIGUSR2);
        alive = 0;
    }
}

char* readInput(){
    int bufferSize = 1024;
    int pos = 0;
    char* buffer = malloc(sizeof(char) * 1024);
    int c; 

    if(!buffer){
        my_str("Couldn't read input!");
        exit(EXIT_FAILURE);
    }

    while(1){
        c = getchar();

        if(c == EOF || c == '\n'){
            buffer[pos] = '\0';
            return buffer;
        } else{
            buffer[pos] = c;
        }
        pos++;

        if(pos >= bufferSize){
            bufferSize += 1024;
            buffer = realloc(buffer, bufferSize);

            if(!buffer){
                my_str("ERROR!");
                exit(EXIT_FAILURE);
            }
        }
    }
}

int my_launch(char** args){
    pid_t wpid;
    int status;

    if((pid = fork()) < 0){
        //error
        exit(1);
    }else if(pid == 0){
        //child
        signal(SIGINT, ctrlc);
        if(execvp(args[0], args) == -1){
            perror("YOU FOOL! ENTER SOMETHING THAT WORKS!");
        }
        exit(EXIT_FAILURE);
    } else{
        alive = 1;
        signal(SIGINT, ctrlc);
        do{
            wpid = waitpid(pid, &status, WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int my_execute(char** args){
    int i;

    if(args[0] == NULL){
        return 1;
    }

    for(i = 0; i < 3; i++){
        if(my_strcmp(args[0], builtin_str[i]) == 0){
            return(*builtin_func[i])(args);
        }
    }

    return my_launch(args);
}

int main(int argc, char* argv[]){
    char* input;
    char** args;
    int currStatus;
    char* cwdBuffer = (char*) malloc(sizeof(char) * 1024);

    do{
        my_str("MINISHELL: ");
        my_str(getcwd(cwdBuffer, 1024));
        my_str(" $: ");
        input = readInput();
        args = my_str2vect(input);
        currStatus = my_execute(args);

        free(input);
        free(args);
    }while(currStatus);

    /*if((pid = fork()) < 0){
        exit(1);
        //error
    }else if (pid == 0){
        //child
        signal(SIGUSR1, sigUSR1);
        signal(SIGUSR2, sigUSR2);
        signal(SIGINT, sigInt);    
        signal(SIGTSTP, sigStp);
        while(1){
            alarm(10);
            pause();
            alarm(0);
        }
    }else{
        //parent
        alive = 1;
        signal(SIGTSTP, ctrlz);
        signal(SIGINT, ctrlc);
        signal(SIGALRM, alarmCatch);
        while(1){
            alarm(10);
            pause();
            alarm(0);
        }
    }*/

    return EXIT_SUCCESS;
}

#include "my.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv){
    char* testStr1 = "Hello World,\t Ralph.";
    //char* testStr2 = "hello \t\t\n class,\nhow are you?";
    int i = 0;
    my_str("setting output...\n");
    char** output = my_str2vect(testStr1);
    my_str("finished setting output...\n");

    for(i = 0; i < 3; i++){
        printf("%s",output[i]);
    }

    return 1;
}

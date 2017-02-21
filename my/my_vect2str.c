#include "my.h"

char* my_vect2str(char** x){
    char* finStr = malloc(sizeof(char));
    int i = 1;

    if(x[i] != NULL){
        finStr = x[i];
        i++;
    }

    while(x[i] != NULL){
        finStr = my_strconcat(finStr, " ");
        finStr = my_strconcat(finStr, x[i]);
        i++;
    }   

    return finStr;
}

#include "my.h"

char** my_str2vect(char* str){
    char** vect;
    int numstrings = 0, startindex = 0, currstring = 0, i = 0;
    int len = my_strlen(str);
    int prevspace = 0;

    for(i = 0; i < len + 1; i++){
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\0'){
            if(!prevspace){
                prevspace = 1;
                numstrings++;
            }
        } else{
            prevspace = 0;
        }
    }

    prevspace = 0;
    vect = (char**) malloc(sizeof(char*) * numstrings + 1);

    for(i = 0; i < len + 1; i++){
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\0'){
            if(!prevspace){
                vect[currstring] = (char*) malloc(sizeof(char) * (i - startindex + 1));
                vect[currstring] = my_strdup(str + startindex);
                *(vect[currstring] + i - startindex) = '\0';
                currstring++;
            }
            prevspace = 1;
        } else{
            if(prevspace)
                startindex = i;
            prevspace = 0;
        }
    }

    vect[numstrings] = NULL;
    return vect;
}

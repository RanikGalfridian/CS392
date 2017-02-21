#include "my.h"

int my_revstr(char* str){
	int wordlen = my_strlen(str);
	char temp;
	if(str == NULL) return -1;
	for(int i = 0; i < wordlen - 1; i++){
		temp = str[i];
		str[i] = str[wordlen - 1];
		str[wordlen - 1] = temp;
		wordlen--;
 	}
 	return my_strlen(str);
}

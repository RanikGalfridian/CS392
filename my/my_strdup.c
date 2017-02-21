#include "my.h"

char* my_strdup(char* str){
	char* newStr = malloc((sizeof str + 1));
	int idx = 0;
	int strLen = my_strlen(str);

	while(str[idx] != '\0'){
		newStr[idx] = str[idx];
		idx++;
	}

	newStr[strLen] = '\0';

	return newStr;
}

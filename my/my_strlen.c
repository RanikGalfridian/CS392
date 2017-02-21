#include "my.h"

int my_strlen(char* str){
	int len = 0;
	if(str == NULL) return -1;
	while(str[len] != '\0'){
		len++;
	}
	return len;
}

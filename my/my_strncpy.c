#include "my.h"

char* my_strncpy(char* dst, char* src, int n){
	int srcLen = my_strlen(src);
	if(n < 0) n = 0;
	if(src == NULL || dst == NULL) return NULL;
	
	if(n >= srcLen){
		my_strcpy(dst, src);
	}else{
		while(n >= 0){
			dst[n-1] = src[n-1];
			n--;
		}
	}

	dst[srcLen] = '\0';

	return dst;
}

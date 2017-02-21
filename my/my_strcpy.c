#include "my.h"

char* my_strcpy(char* dst, char* src){
	int srcLen = my_strlen(src);
	int idx = 0;
	if(src == NULL || dst == NULL) return NULL;
	while(idx < srcLen){
		dst[idx] = src[idx];
		idx++;
	}

	dst[srcLen] = '\0';

	return dst;
}

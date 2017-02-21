#include "my.h"

char* my_strcat(char* dst, char* src){
	int sidx = 0;
	int dstLen = my_strlen(dst);

	if(dst == NULL) return NULL;
	if(src == NULL) return dst;
	
	while(src[sidx] != '\0'){
		dst[dstLen] = src[sidx];
		dstLen++;
		sidx++;
	}

	dst[dstLen] = '\0';

	return dst;
}

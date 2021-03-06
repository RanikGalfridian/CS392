#include "my.h"

char* my_strnconcat(char* a, char* b, int n){
	int aidx = 0;
	int bidx = 0;
	int idx = 0;
	int aLen = my_strlen(a);
	int bLen = my_strlen(b);
	char* newStr = malloc(sizeof(aLen + bLen));

	if(a == NULL && b == NULL) return NULL;
	if(n < 0) n = 0;
	
	if(a == NULL){
		newStr = malloc(sizeof(b));
		while(bidx < n){
			newStr[idx] = b[idx];
			idx++;
			bidx++;
		}
	}else if(b == NULL){
		newStr = malloc(sizeof(a));
		while(a[aidx] != '\0'){
			newStr[idx] = a[idx];
			idx++;
			aidx++;
		}
	}else{
		while(a[aidx] != '\0'){
			newStr[idx] = a[aidx];
			idx++;
			aidx++;
		}
	
		while(bidx < n){
			newStr[idx] = b[bidx];
			idx++;
			bidx++;
		}
	}

	newStr[aLen + bLen] = '\0';

	return newStr;
}

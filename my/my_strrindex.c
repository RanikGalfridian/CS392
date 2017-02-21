#include "my.h"

int my_strrindex(char* myStr, char myChar){
	int currIdx = 0;
	int foundIdx = -1;
	if(myStr == NULL) return -1;
	while(myStr[currIdx] != '\0'){
		if(myStr[currIdx] == myChar) foundIdx = currIdx;
		currIdx++;
	}
	return foundIdx;
}

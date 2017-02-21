#include "my.h"

char* my_strrfind(char* strOne, char strTwo){
	int currIdx = 0;
	int foundIdx = -1;

	if(strOne == NULL) return NULL;
	if(my_strindex(strOne, strTwo) == -1) return NULL;

	while(strOne[currIdx] != '\0'){
		if(strOne[currIdx] == strTwo) foundIdx = currIdx;
		currIdx++;
	}

	for(int i = 0; i < foundIdx; i++){
		strOne++;
	}

	return strOne;
}

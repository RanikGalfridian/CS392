#include "my.h"

char* my_strfind(char* strOne, char strTwo){

	if(strOne == NULL) return NULL;
	if(my_strindex(strOne, strTwo) == -1) return NULL;

	/* Incrementally searches through strOne until it finds strTwo */
	while(strOne[0] != strTwo){
		if(strOne[0] == '\0') return NULL;
		strOne++;
	}

	return strOne;
}

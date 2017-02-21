#include "my.h"

int my_strindex(char* str, char car){
	int idx = 0;
	if (str == NULL) return -1;
	while(str[idx] != car){
		if(str[idx] == '\0') return -1;
		idx++;
	}
	return idx;
}

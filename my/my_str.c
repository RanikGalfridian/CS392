#include "my.h"

void my_str(char* str){
	if(str != NULL){
		/* Cycles through each character in the string, printing them individually until reaching a null character. */
		while(str[0] != '\0'){
			my_char(str[0]);
			str = str + 1;
		}
	}
}

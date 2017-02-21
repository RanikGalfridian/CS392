#include "my.h"

int my_atoi(char* str){
	int len;
	int result = 0;
	int i;
	int neg = 0;
	int found = 0;

	if(str == NULL) return 0;
	len = my_strlen(str);
	for(i = 0; i < len; i++){
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-'){
			if(str[i] != '-') found = 1;
			if(str[i] == '-') neg = !neg;
			else result = (result * 10) + str[i] - 48;
		}else if(found){
			break;
		}
	}
	if(neg) result = result * -1;
	return result;
}

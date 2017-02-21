#include "my.h"

int my_strncmp(char* a, char* b, int n){
	int count = 0;
	int lengthA = my_strlen(a);
	int lengthB = my_strlen(b);
	int equal = 0;
	int less = 0;
	int more = 0;

	if((a == NULL && b == NULL) || n == 0) return 0;
	if(a == NULL && b != NULL) return -1;
	if(a != NULL && b == NULL) return 1;
	if(n < 0) n = 0;

	if(n < lengthA || n < lengthB){
		if(a[count] == b[count]){
			while(count < n){
				if(a[count] == b[count]){ 
					equal = 1;
					less = 0;
					more = 0;
				}
				else if(a[count] < b[count]) {
					equal = 0;
					less = 1;
					more = 0;
					break;
				}else{
					equal = 0;
					less = 0;
					more = 1;
					break;
				}
				count++;
			}
		}else if(a[count] < b[count]){
			equal = 0;
			less = 1;
			more = 0;
		}else{
			equal = 0;
			less = 0;
			more = 1;
		}
		
		if(equal == 1) return 0;
		else if(less == 1) return -1;
		else return 1;
	}else{
		return my_strcmp(a, b);
	}
}

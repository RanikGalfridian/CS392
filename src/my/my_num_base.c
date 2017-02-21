#include "my.h"

long power(int base, int pow){
	long finNum = 1;
	while(pow > 0){
		finNum = finNum * base;
		pow--;
	}
	return finNum;
}

int base;
int d;
long newNum;
void my_num_base(int num, char* word){
	int d = 1;
	newNum = num;
	if(word == NULL || my_strlen(word) == 0){ 
		my_str("ERROR: String must be non-null and non-empty!");
		return;
	}
	if(num < 0){
		newNum = newNum * -1;
		my_char('-');
	}
	base = my_strlen(word);
	if(base == 1){
		while(newNum > 0){ 
			my_char(word[0]);
			newNum--;
		}
		return;
	}
	while (newNum > power(base, d)){
		d++;
	}
	d--;
	while(d >= 0){
		my_char(word[newNum / power(base, d)]);
		newNum = newNum % (power(base, d));
		d--;
	}
}

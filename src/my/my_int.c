
#include "my.h"


void my_int(int a){
	int b = 1000000000;
	int mult = 1;
	if(a == 0) my_char(48);
	if(a < 0) {
		my_char('-');
		mult = -1;
	}
	while(b > 0){
		if(a / b != 0) my_char( ((a / b) % 10) * mult + 48);
		b = b / 10;
	}
}

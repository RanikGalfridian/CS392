

int power(int base, int pow){
	int finNum;
	if(pow == 0) return 1;
	else if(pow == 1) return base;
	else{
		while(pow > 1){
			finNum = base * base;
			pow--;
		}
	}
	return finNum;
}

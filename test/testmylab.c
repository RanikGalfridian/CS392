#include "my.h"
#include "stdio.h"


int main(){
  for(int i = 1; i < 101; i++){
    if((i % 3) == 0){
      my_char('F');
      my_char('\n');
    }
    else if((i % 5) == 0){
      my_char('B');
      my_char('\n');
    }
    else if((i % 5) == 0 && (i % 3) == 0){
      my_char('F');
      my_char('B');
      my_char('\n');
    } 
    else
      printf("%d\n", i);
  }
}

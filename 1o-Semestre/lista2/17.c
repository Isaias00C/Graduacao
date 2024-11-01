#include <stdio.h>

int main(){
  int num;
  int num2x = 1, num1x = 1, num0x = 0;

  scanf("%d", &num);

  while(num0x <= num){
    printf("%d ", num0x);
    num0x = num1x;
    num1x = num2x;
    num2x = num1x + num0x;
  }

  printf("%d\n", num0x);
  return 0;
}

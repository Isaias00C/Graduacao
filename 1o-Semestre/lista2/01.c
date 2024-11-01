#include <stdio.h>

int main(){
  char a;
  int cont = 0;
  scanf("%c", &a);
  a = a - '0';
  
  for(int i = 0; i < 8; i++){
    if(((int)a)%2 == 1){
      cont++;
    }
    a = a >> 1;
  }

  printf("%d\n", cont);
  return 0;
}

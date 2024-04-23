#include <stdio.h>

int main(){
  int a, cont = 0;

  scanf("%d", &a);
  
  for(int i = 0; i < sizeof(a)*8; i++){
    if(a/2 == 1){
      cont++;
    }
    a = a/2;
  }

  printf("%d\n", cont);
  
  return 0;
}

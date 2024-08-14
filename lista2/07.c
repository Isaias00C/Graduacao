#include <stdio.h>

int main(){
  int a, soma = 0;

  for(int i = 0; i < 10; i++){
    scanf("%d", &a);
    soma += a;
  }

  printf("%d\n", soma);
  
  return 0;
}

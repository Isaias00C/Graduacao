#include <stdio.h>

int main(){
  int soma = 0;

  for(int i = 0; i < 50; i++){
    soma += 2*i;
  }

  printf("%d\n", soma);
  
  return 0;
}

#include <stdio.h>

int main() {
  int n, i = 2, j, sum = 0, cont = 0, eh_primo;
  int divisores;
  
  scanf("%d", &n);

  while (cont < n) {
    j = 1;
    divisores = 0;
    
    do{
      if (i % j == 0) {
        divisores++;
      }
      j++;
    }while(j <= i);

    if(divisores != 2){
      eh_primo = 0;
    }else
      eh_primo = 1;
    
    if (eh_primo) {
      sum += i;
      cont++;
    }
    i++;
  }
  printf("\n%d\n", sum);
  return 0;
}

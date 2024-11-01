#include <stdio.h>

int main(){
  int N, cent, dez, uni;

  scanf("%d", &N);

  uni = N%10;
  dez = (N%100)/10;
  cent = (N%1000)/100;

  printf("%d centenas, %d dezenas e %d unidades", cent, dez, uni);
  return 0;
}

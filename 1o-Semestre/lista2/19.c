#include <stdio.h>

int main(){
  int anos = 0, hChico = 150, hZe = 110;

  while(hChico >= hZe){
    anos++;
    hChico += 2;
    hZe += 3;
  }

  printf("%d\n", anos);
  
  
  return 0;
}

#include <stdio.h>

int main(){
  float E = 0.0;
  int fatorial, i, j;

  for(i = 0; i < 5; i++){
    fatorial = 1;
    for(j = 2*i; j > 0; j--){
      fatorial = fatorial*j;
    }
    E += (i)/(float)fatorial;
  }

  printf("%f", E);
  
  return 0;
}

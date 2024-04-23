include <stdio.h>

int main(){
  float E = 1.0;
  int N, fatorial, i, j;

  scanf("%d", &N);

  for(i = 1; i <= N; i++){
    fatorial = 1;
    for(j = i; j > 0; j--){
      fatorial = fatorial*j;
    }
    E += 1/(float)fatorial;
  }

  printf("%f", E);
  
  return 0;
}

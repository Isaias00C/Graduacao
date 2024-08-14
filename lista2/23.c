#include <stdio.h>

int main(){
  int n, i;

  scanf("%d", &n);
  
  for(i = 2; i < n; i++){
    if(n%i == 0){
      printf("nao eh primo\n");
      return 0;
    }
  }
  printf("eh primo\n");
  return 0;
}

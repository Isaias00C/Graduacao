#include <stdio.h>

int main(){
  int N, num, max, cont = 0, i;

  scanf("%d", &N);
  
  for(i = 0; i < N; i++){
    scanf("%d", &num);
    if(i == 0){
      max = num;
      continue;
    }

    if(num == max){
      cont++;
    }else if(num > max){
      max = num;
      cont = 1;      
    }
  }

  printf("max = %d\nqtd de vezes = %d\n", max, cont);
  return 0;
}

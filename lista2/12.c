#include <stdio.h>

int main(){
  int N;

  scanf("%d", &N);
  
  for(int i = 0; i <= N; i++){
    if(i%10 == 0){
      printf("%d\n", i);
    }else
      printf("%d ", i);
  }
  
  return 0;
}

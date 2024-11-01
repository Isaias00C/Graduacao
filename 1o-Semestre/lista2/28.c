#include <stdio.h>

int verificador(int v){
  if(v > 0){
    return 1;
  }else if(v < 0){
    return -1;
  }else
    return 0;
}
int main() {
  int num;
  scanf("%d", &num);
  printf("%d",verificador(num));
  return 0;
}

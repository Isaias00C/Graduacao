#include <stdio.h>

int dobro(int x){
  x = 2*x;
  return x;
}

int main() {
  int a;
  scanf("%d", &a);
  printf("%d\n", dobro(a));
  return 0;
}

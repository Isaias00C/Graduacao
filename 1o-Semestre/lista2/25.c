#include <stdio.h>

int main() {
  int a = 999, b = 999, p, eh_palindromo;
  int d0, d1, d2, d3, d4, d5;
  do {
    p = a * b;

    d0 = p % 10;
    d1 = (p % 100) / 10;
    d2 = (p % 1000) / 100;
    d3 = (p % 10000) / 1000;
    d4 = (p % 100000) / 10000;
    d5 = (p % 1000000) / 100000;

    if(d0 == d5 && d1 == d4 && d2 == d3){
      eh_palindromo = 1;
    }else
      eh_palindromo = 0;

    if (eh_palindromo) {
      printf("%d * %d = %d\n", a, b, p);
      return 0;
    } else {
      a--;
      if (a < 1) {
        a = b;
        a--;
        b--;
      }
    }
  } while (1);
  return 0;
}

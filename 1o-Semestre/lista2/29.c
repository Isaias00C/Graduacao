#include <stdio.h>

int seg_totais(int hora, int min, int seg){
  seg += 60*min;
  seg += 3600*hora;
  return seg;
}

int main() {
  int hora, min, seg;
  scanf("%d %d %d", &hora, &min, &seg);
  printf("%d segundos", seg_totais(hora, min, seg));
  return 0;
}

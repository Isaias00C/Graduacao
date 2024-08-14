#include <stdio.h>

int main(){
  int opcao;
  float v;
  
  while(1){  
    printf("1- de km/h para m/s\n");
    printf("2- de m/s para km/h\n");
    printf("0- encerra o programa\n");
    printf("\ninsira a opcao de transformacao: ");
    scanf("%d", &opcao);
    
    if(opcao == 1){
        printf("\nDigite o valor da velocidade(km/h): ");
        scanf("%f", &v);
        printf("O valor da velocidade em m/s eh: %.2f\n\n", v/3.6);
    }else if(opcao == 2){
      printf("\nDigite o valor da velocidade(m/s): ");
      scanf("%f", &v);
      printf("O valor da velocidade em km/h eh: %.2f\n\n", v*3.6);
    }else if(opcao == 0){
      break;
    }else
      printf("\nDigite uma opcao valida!\n\n");
  }
  return 0;
}

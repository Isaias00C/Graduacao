#include <stdio.h>

int main(){
  float salario = 2000.0;  //salario 1995
  float salario_do_ano, aumento;
  int ano; 

  aumento = salario*0.015;
  salario_do_ano = salario*1.015;  //salario 1996
  
  for(ano = 1997; ano < 2025; ano++){
    salario = salario_do_ano;  //salario do ano anterior
    salario_do_ano = salario + 2*aumento;  //salario do ano reajustado 
    
    aumento = salario_do_ano - salario;  //aumento que ele teve no ano    
  }

  printf("%f\n", salario_do_ano);
  
  return 0;
}

//Problema: criar um vetor de strings usando alocaçao dinamica
#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtdStrings;
    scanf("%d", &qtdStrings);

    char **vetor = malloc(sizeof(char) * qtdStrings);

    if(!vetor) return 0; //verificando a validade da alocaçao de vetor

    //preenchendo o vetor para as strings
    for(int i = 0; i < qtdStrings; i++){
        printf("entre com o tamanho da string: ");
        int tamanhoString;
        scanf("%d", &tamanhoString);
        
        //alocando a string
        char *c = malloc(sizeof(char) * (tamanhoString + 1));
        if(!c) return 0; //verificando a validade da alocaçao de c

        //comendo do 'enter' dado no scanf anterior
        getchar();

        printf("entre com sua string: ");
        gets(c);
        vetor[i] = c;

    }

    //imprimindo as strings
    for(int i = 0; i < qtdStrings; i++){
        puts(vetor[i]);
    }


    //fim liberar os dois mallocs
    for(int i = 0; i < qtdStrings; i++){
        free(vetor[i]);
    }

    free(vetor);

}
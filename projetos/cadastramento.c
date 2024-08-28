#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cadastrar(int i);
void recuperarInfos();

int main(){
    int i = 1;

    while(1){
        printf("Selecione uma opcao: \n");
        printf("1. Cadastrar Novo Usuario.\n");
        printf("2. Recuperar Dados de Usuario.\n");
        printf("3. Fim.\n");

        int opcao;
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                cadastrar(i);
                i++;
                break;
            case 2:
                recuperarInfos();
                break;
            default:
                return 0;
        }
    }
}

void cadastrar(int i){
    char nome[100], data[11], cpf[15]; //dd/mm/aaaa -> 10 caracteres ; xxx.xxx.xxx-xx -> 14 caracteres

    FILE* filename = fopen("cadastramento.txt", "a");

    getchar();

    printf("Nome: ");
    gets(nome);

    printf("CPF: ");
    gets(cpf);

    printf("Data do Nascimento: ");
    gets(data);

    fprintf(filename, "Id do Usuario: %d\n", i);
    fprintf(filename, "Nome: %s\n", nome);
    fprintf(filename, "CPF: %s\n", cpf);
    fprintf(filename, "Data de Nascimento: %s\n", data);
    fprintf(filename, "\n\n------------------------------------\n\n");

    fclose(filename);

}

void recuperarInfos(){
    char *cpf = malloc(15*sizeof(char));
    if(!cpf) {
        printf("falha no malloc!\n");
        return;
    }
    printf("Buscar Usuario de CPF: ");
    gets(cpf);
    char line = strcat("CPF: ", cpf); 

    FILE* filename = fopen("cadatramento.txt", "r");
    
    char buffer[1000];

    while(fgets(buffer, 999, filename)!=NULL){
        printf("%s", buffer);
        
        if(strcmp(buffer, line)) {
            puts(buffer);
            return;
        }
    }

    free(cpf);
    fclose(filename);
}
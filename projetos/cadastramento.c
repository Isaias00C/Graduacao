#include <stdio.h>
#include <string.h>

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

        //getchar();
    }
}

void cadastrar(int i){
    char nome[100], data[11], cpf[15]; //dd/mm/aaaa -> 10 caracteres ; xxx.xxx.xxx-xx -> 14 caracteres

    FILE* filename = fopen("cadastramento.txt", "a");

    getchar();

    printf("Nome: ");
    gets(nome);
    //getchar();

    printf("CPF: ");
    gets(cpf);
    //getchar();

    printf("Data do Nascimento: ");
    gets(data);
    //getchar();

    fprintf(filename, "Id do Usuario: %d\n", i);
    fprintf(filename, "Nome: %s\n", nome);
    fprintf(filename, "CPF: %s\n", cpf);
    fprintf(filename, "Data de Nascimento: %s\n", data);
    fprintf(filename, "\n\n------------------------------------\n\n");

    fclose(filename);

}

void recuperarInfos(){
    char cpf[15];
    printf("Buscar Usuario de CPF %s", &cpf);

    FILE* filename = fopen("cadatramento.txt", "r");
    
    char* s;

    if(strcmp(cpf, )){

    }

}
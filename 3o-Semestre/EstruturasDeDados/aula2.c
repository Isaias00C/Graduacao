#include <Stdio.h>

typedef struct TData{
    int ano;
    int mes;
    int dia;
}Data;

typedef struct TStudent{
    char nome[50];
    //Data data;
    int idade;
}Student;

int main(){
    Data data = {
        10,
        12,
        24
    };

    Student student = {
        "Isaias",
        //data,
        24
    };

    printf("Tamanho do data: %ld\n", sizeof(data));
    printf("Tamanho do student: %ld\n", sizeof(student));
}
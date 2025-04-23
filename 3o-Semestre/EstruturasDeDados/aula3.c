//alocação dinamica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //um pouco de ponteiros
    int x = 1000; //variavel do tipo inteiro (4bytes)
    char *p = &x; //ponteiro para char (1 byte)

    printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3));
    printf("%02x %02x %02x %02x\n", p, p+1, p+2, p+3);

    //alocação dinamica

    int *_p = malloc(10*sizeof(int)); //um ponteiro para inteiros alocado para uma memoria do tamanho de 10 inteiros (40bytes)

    if(!_p) {
        printf("Error na alocação\n");
        return 0;
    }

        
    for(int i = 0; i < 10; ++i){
        _p[i] = i+1;

    }

    for(int i = 0; i < 10; ++i){
        printf("%d ", *_p);
        _p++ ? printf("True\n") : printf("False");
    }

    //memcpy (ponteiro de partida, ponteiro de destino, tamanho da memoria)

    int *q = malloc(10*sizeof(int));

    printf("%d\n", *q);

    memcpy(p, q, 10);

    for(int i = 0; i < 10; ++i){
        printf("%d ", *q++);
    }
    printf("\n");

    //menset (ponteiro de partida, valor que será setado, quantas posições de memoria serão setadas)

    int *v = malloc(10*sizeof(int));

    memset(v, 0, 10);

    for(int i = 0; i < 10; ++i){
        printf("%d ", *v++);
    }

    free(_p);
    free(p);
    free(q);
    free(v);

    return 0;
}
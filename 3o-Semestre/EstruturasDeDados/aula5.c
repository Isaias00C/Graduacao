#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto2D{
    float x;
    float y;
}Ponto2D;

double distancia(Ponto2D* p1, Ponto2D* p2){
    return sqrt((p1->x - p2->x)*(p1->x - p2->x) + (p1->y - p2->y)*(p1->y - p2->y));
}

Ponto2D pontoMedio(Ponto2D* p1, Ponto2D* p2){
    Ponto2D p3;

    p3.x = (p1->x + p2->x) / 2;
    p3.y = (p1->y + p2->y) / 2;

    return p3;
}

Ponto2D* PonteiroParaPontoMedio(Ponto2D* p1, Ponto2D* p2){
    Ponto2D* p3 = malloc(sizeof(Ponto2D));

    if(p3 == NULL){
        printf("Erro no malloc");
        return NULL;
    }

    p3->x = (p1->x + p2->x) / 2;
    p3->y = (p1->y + p2->y) / 2;

    return p3;
}

int main(){
    Ponto2D* p1 = malloc(sizeof(Ponto2D));
    Ponto2D* p2 = malloc(sizeof(Ponto2D));

    p1->x = 0;
    p1->y = 0;

    p2->x = 3;
    p2->y = 4;

    printf("Distancia entre os pontos: %.2lf\n", distancia(p1, p2));

    Ponto2D p3 = pontoMedio(p1, p2);
    printf("Ponto medio entre p1 e p2: %.2lf %.2lf\n", p3.x, p3.y);

    Ponto2D* p4 = PonteiroParaPontoMedio(p1, p2);
    printf("Ponto medio entre p1 e p2 usando uma funcao que retorna um ponteiro: %.2lf %.2lf", p4->x, p4->y);

    free(p4);
    free(p2);
    free(p1);

    return 0;
}
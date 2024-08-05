#include <stdio.h>

int p[100], v[100];
int mochila(int pesoMax, int t);
int max(int a, int b);

int main(){
    int tamanho, capacidade;
    printf("tamanho: ");
    scanf("%d", &tamanho);
    printf("capacidade: ");
    scanf("%d", &capacidade);

    printf("vetor de pesos: ");
    for(int i = 0; i < tamanho; i++){
        scanf("%d", &p[i]);
    }
    printf("vetor de valores: ");
    for(int i = 0; i < tamanho; i++){
        scanf("%d", &v[i]);
    }

    printf("valor maximo roubado: %d\n", mochila(capacidade, tamanho));
}

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int mochila(int pesoMax, int t){
    if(pesoMax == 0  || t == 0) return 0;

    if(p[t-1] > pesoMax) mochila(pesoMax, t-1);
    else{
        int incluindo = v[t-1] + mochila(pesoMax - v[t-1], t-1);
        int nao_incluindo = mochila(pesoMax, t-1);
        return max(incluindo, nao_incluindo);
    }
}
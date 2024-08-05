#include <stdio.h>

int p[100], v[100], memo[100][100], booleana[100];
int mochila(int pesoMax, int t);
int max(int a, int b);

int main(){
    int tamanho, capacidade;
    printf("tamanho: ");
    scanf("%d", &tamanho);
    printf("capacidade: ");
    scanf("%d", &capacidade);

    //preparando o memo
    for(int i = 0; i <= capacidade; i++){
        memo[capacidade][i] = 0;
    }
    for(int i = 0; i <= tamanho; i++){
        memo[i][tamanho] = 0;
    }
    for(int i = 1; i <= capacidade; i++){
        for(int j = 1; j <= tamanho; j++){
            memo[i][j] = -1;
        }
    }
    
    
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
    if(memo[pesoMax][t] == -1){
        if(pesoMax == 0  || t == 0) return 0;

        if(p[t-1] > pesoMax) mochila(pesoMax, t-1);
        else{
            int incluindo = v[t-1] + mochila(pesoMax - p[t-1], t-1);
            int nao_incluindo = mochila(pesoMax, t-1);
            
            memo[pesoMax][t] = max(incluindo, nao_incluindo);
            return max(incluindo, nao_incluindo);
        }
    }else{
        return memo[pesoMax][t];
    }
}

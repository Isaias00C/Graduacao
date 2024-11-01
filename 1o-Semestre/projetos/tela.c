#include <stdio.h>
#include <time.h>
#define t 52



void questao2(){
    char grid[t][2*t];
    int i, j;

    //inicializando o grid
    for(i = 0; i < t; i++){
        for(j = 0; j < 2*t; j++){
            grid[i][j] = '.';
        }
    }

    //criando o bloco inicial
    int xi, yi;
    xi = 10;
    yi = 3;

    grid[xi][yi] = '1';
    grid[xi + 1][yi] = '1';
    grid[xi][yi + 1] = '1';
    grid[xi + 1][yi + 1] = '1';

    int dx = 1, dy = 1;
    //rodando

    while(1){

        //condicao de batida vertical
        if(xi + dx == (t-1) && dx == 1) {
            dx = -1;
        }else if(xi == 0 && dx == -1){
            dx = 1;
        }

        //condicao de batida horizontal
        if(yi + dy == (2*t - 1) && dy == 1){
            dy = -1;
        }else if(yi == 0 && dy == -1){
            dy = 1;
        }
        
        //atualizando a posicao
        grid[xi][yi] = '.';
        grid[xi + 1][yi] = '.';
        grid[xi][yi + 1] = '.';
        grid[xi + 1][yi + 1] = '.';

        xi = xi + dx;
        yi = yi + dy;

        grid[xi][yi] = '1';
        grid[xi + 1][yi] = '1';
        grid[xi][yi + 1] = '1';
        grid[xi + 1][yi + 1] = '1';

        //plotando o grid

        for(i = 0; i < t; i++){
            for(j = 0; j < 2*t; j++){
                printf("%c ", grid[i][j]);
            }

            printf("\n");
        }

        //printf("\n\n\n");
        sleep(0.1);
    }
}

int main(){
    questao2();
    return 0;
}

//sem Struct
#include <stdio.h>
#include <stdlib.h>

void read(FILE* fp, int* width, int* height, int* maxVal, char** img);
void write(int* width, int* height, int* maxVal, char** img);

int main(){
    char input[40];
    printf("nome do arquivo pgm a ser lido: ");
    gets(input);

    FILE* filename;
    filename = fopen(input, "r");

    int pos1, pos2, pos3; //posicao da memoria para onde os ponteiros seguintes vao apontar
    int* width, height, maxVal; //passando as informaçoes do arquivo por referencia para as funcoes
    width = &pos1;
    height = &pos2;
    maxVal = &pos3;
    int** img;

    read(filename, width, height, maxVal, img);

    write(width, height, maxVal, img);
}

void read(FILE* fp, int* width, int* height, int* maxVal, char** img){
    img = (char*)malloc((*width)*sizeof(char*));
    for(int i = 0; i < *width; i++){
        img[i] = (char)malloc((*height)*sizeof(char));
    }

    char type[2];
    fscanf(fp, "%s", &type);

    if(fgetc(fp) == '#'){
        while(fgetc(fp) != '\n') ;
    }

    int w, h, v;
    fscanf(fp, "%d %d", &w, &h);
    *width = w;
    *height = h;
    
    fscanf(fp, "%d", &v);
    *maxVal = v;

    for(int i = 0; i < *width; i++){
        for(int j = 0; j < *height; j++){
            img[i][j] = fgetc(fp);
        }
    }
}

void write(int* width, int* height, int* maxVal, char** img){
    printf("nome do arquivo de saida: ");
    char output[20];
    gets(output);

    FILE* filenameOutput;
    filenameOutput = fopen(output, "w");

    fprintf(filenameOutput, "P5\n"); //escrevendo o tipo do arquivo 

    fprintf(filenameOutput, "%d %d", *width, *height); //passando as dimensoes da imagem

    fprintf(filenameOutput, "%d", *maxVal); // escrevendo o valor maximo da cor cinza

    for(int i = 0; i < *width; i++){
        for(int j = 0; j < *height; j++){
            if(i!=j) fprintf(filenameOutput, "%c", img[i][j]);
            else fprintf(filenameOutput, "%c", 0);
        }
    }

    for(int i = 0; i < *width; i++){
        free(img[i]);
    }

    free(img);

    fclose(filenameOutput);

}


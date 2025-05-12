#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

typedef struct tagElementList{
    byte* data; //ponteiro para o dado a ser armazenado na lista
    void* nextELement; //ponteiro para o proximo elemento da lista
}TElementList;

typedef struct tagList{
    int nElements; //numero de elementos da lista
    int sizeELement; //tamanho do elemento da lista
    TElementList* first; //ponteiro para o primeiro elemento da lista
    TElementList* last; //ponteiro para o ultimo elemento da lista
    TElementList* curr; //ponteiro para o elemento atual da lista

}TList;

//metodos de acesso do objeto lista

void createList(TList* list, int sizeElement);
void destroyList(TList* list);
byte* firstList(TList* list);
byte* nextList(TList* list);
byte* lastList(TList* list);
bool insertList(TList* list, byte* data);
bool removeLastList(TList* list);
void dumpItem(TElementList* item, int size);
void dumpList(TList* list);

int main(){
    TList list;

    createList(&list, sizeof(int));
    dumpList(&list);

    byte a = 1;

    insertList(&list, &a);
    dumpList(&list);

    byte b = 2;

    insertList(&list, &b);
    dumpList(&list);

    byte c = 7;

    insertList(&list, &c);
    dumpList(&list);

    removeLastList(&list);
    dumpList(&list);

    return 0;
}

void createList(TList* list, int sizeELement){
    list->nElements = 0;
    list->sizeELement = sizeELement;
    list->first = NULL;
    list->last = NULL;
    list->curr = NULL;
}

void destroyList(TList* list){
    if(list->nElements == 0){
        list->nElements = 0;
        list->sizeELement = 0;
        list->first = NULL;
        list->last = NULL;
        list->curr = NULL;
    }
}

byte* firstList(TList* list){
    return list->first->data;
}

byte* nextList(TList* list){
    if(list->curr->nextELement != NULL) list->curr = list->curr->nextELement;
    return list->curr->data;
}

byte* lastList(TList* list){
    return list->last->data;
}

bool insertList(TList* list, byte* data){
    TElementList* item;
    //testa se é o primeiro elemento da lista
    if(list->nElements == 0){
        //aloca area para o elemetno da lista
        if( (item = malloc(sizeof(TElementList))) != NULL){
            //aloca area para o dado
            if( (item->data = malloc(list->sizeELement)) != NULL){
                //copia o dado
                memcpy(item->data, data, list->sizeELement);
                //seta NULL para o proximo elemento pois a lista tem um so elemento
                item->nextELement = NULL;
                //atualiza os ponteiros da lista
                list->first = item;
                list->curr = item;
                list->last = item;
                list->nElements++;
            }
        }
    }else{
        //aloca area para o elemetno da lista
        if( (item = malloc(sizeof(TElementList))) != NULL){
            list->last->nextELement = item;
            if(list->nElements == 1){
                list->first->nextELement = item;
            }

            //aloca area para o dado
            if( (item->data = malloc(list->sizeELement)) != NULL){
                //copia o dado
                memcpy(item->data, data, list->sizeELement);
                item->nextELement = NULL;
                list->last = item;
                list->curr = item;
                list->nElements++;
            }
        }
    }
}

bool removeLastList(TList* list){
    if (list->nElements == 0) return false;
    
    list->curr = list->first;

    for(int i = 0; i < ((list->nElements) - 2); i++){
        list->curr = list->curr->nextELement;
    }

    TElementList* flag;

    flag = list->last;

    list->last = list->curr;

    list->curr->nextELement = NULL;

    list->nElements--;

    if(list->nElements == 0){
        list->first = NULL;
        list->curr = NULL;
        list->last = NULL;
    }

    free(flag->data);
    free(flag);
}

void dumpItem(TElementList* item, int size){
    int i;
    byte* point;
    printf("********************************\n");
    
    printf("Data = %x\n", item->data);
    printf("next = %02x\n", item->nextELement);
    printf("Conteudo data:\n");

    point = (byte*)(item->data);

    for(i = 0; i < size; i++){
        printf("%04x : %02x : %03d : %c\n", point, (*point), (*point), (*point));
        point++;
    }

    printf("********************************\n");
}

void dumpList(TList* list){
    TElementList* item;

    printf("No de elementos da lista: %d\n",list-> nElements);
    printf("Tamanho dos elementos:    %d\n", list->sizeELement);
    printf("Ponteiro first:           %02x\n", list->first);
    printf("Ponteiro last:            %02x\n", list->last);
    printf("Ponteiro curr:            %02x\n", list->curr);

    if(list->first != NULL){   
        item = list->first;
        while(item != NULL){
            dumpItem(item, list->sizeELement);
            item = item->nextELement;
        }
    }

    printf("-------------------------------\n");
}


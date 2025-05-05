#include <stdio.h>
#include <stdbool.h>

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
byte* firstList(TLIst* list);
byte* nextList(TList* list);
byte* lastList(TList* list);
bool insertList(TList* list, byte* data);
bool removeLastList(TList* list);

int main(){

    return 0;
}

void createList(TList* list, int sizeELement){
    list->nElements = 0;
    list->sizeELement = sizeELement;
    list->first = NULL;
    list->last = NULL;
    list->curr = NULL;
}

void destroyList(TLIst* list){
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

byte* nextList(TList list){
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
                memcpy(item->data, data, item->sizeELement);
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
                memcpy(item->data, data, item->sizeELement);
                item->nextELement = NULL;
                list->last = item;
                list->curr = item;
                list->nElements++;
            }
        }
    }


}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

typedef struct tagElementList{
    byte* data; // ponteiro para o dado a ser armazenado na lista
    void* nextElement; // ponteiro para o proximo elemento da lista
    void* prevElement;
}TElementList;

typedef struct tagList{
    int nElements; // numero de elementos da lista
    int sizeELement; // tamanho do elemento da lista
    TElementList* first; // ponteiro para o primeiro elemento da lista
    TElementList* last; // ponteiro para o ultimo elemento da lista
    TElementList* curr; // ponteiro para o elemento atual da lista
    bool isCircle; // indica se a lista é circular
    bool isDoubly; // indica se a lista é duplamente encadeada
}TList;

// metodos de acesso do objeto lista

void createList(TList* list, int sizeElement, bool isCircle, bool isDoubly);
void destroyList(TList* list);
byte* firstList(TList* list);
byte* nextList(TList* list);
byte* lastList(TList* list);
byte* prevList(TList* list);
bool insertList(TList* list, byte* data);
bool removeLastElement(TList* list);
bool removeLastElement(TList* list);
bool removeCurrElement(TList* list);
void dumpItem(TElementList* item, int size);
void dumpList(TList* list);
void showItem(TElementList* item, int position);
void showItems(TList* list, int numberOfElements);
bool goFirst(TList* list);
bool goNext(TList* list);

int main(){
    TList list;

    createList(&list, sizeof(int), true, true);
    dumpList(&list);

    int a = 1;

    insertList(&list, &a);
    dumpList(&list);

    int b = 2;

    insertList(&list, &b);
    dumpList(&list);

    int c = 7;

    insertList(&list, &c);
    dumpList(&list);

    int d = 15;
    insertList(&list, &d);
    dumpList(&list);

    goFirst(&list);
    goNext(&list);
    goNext(&list);

    removeCurrElement(&list);
    dumpList(&list);

    return 0;

}

void createList(TList* list, int sizeELement, bool isCircle, bool isDoubly){
    list->nElements = 0;
    list->sizeELement = sizeELement;
    list->first = NULL;
    list->last = NULL;
    list->curr = NULL;
    list->isCircle = isCircle;
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
    if(list->curr->nextElement != NULL) list->curr = list->curr->nextElement;
    return list->curr->data;
}

byte* lastList(TList* list){
    return list->last->data;
}

byte* prevList(TList* list){
    if(list->isDoubly) list->curr = list->curr->prevElement;
    return list->curr->data;
}

bool insertList(TList* list, byte* data){
    TElementList* item;

    // testa se é o primeiro elemento da lista
    if(list->nElements == 0){
        
        // aloca area para o elemetno da lista
        if( (item = malloc(sizeof(TElementList))) != NULL){
            
            // aloca area para o dado
            if( (item->data = malloc(list->sizeELement)) != NULL){
                
                // copia o dado
                memcpy(item->data, data, list->sizeELement);
                
                // seta o proximo elemento
                item->nextElement = list->isCircle ? item : NULL;
                
                if(list->isDoubly) {

                    // seta o elemento anterior
                    item->prevElement = list->isCircle ? item : NULL;
                }

                //atualiza os ponteiros da lista
                list->first = item;
                list->curr = item;
                list->last = item;
                list->nElements++;

            }
        }
    }else{
        
        // aloca area para o elemetno da lista
        if( (item = malloc(sizeof(TElementList))) != NULL){
            
            // atualiza o ponteiro para o proximo elemento do ultimo anterior para o item
            list->last->nextElement = item;
            if(list->nElements == 1){
                list->first->nextElement = item;
                list->first->prevElement = list->isCircle ? item : NULL;
            }

            // aloca area para o dado
            if( (item->data = malloc(list->sizeELement)) != NULL){
                
                // copia o dado
                memcpy(item->data, data, list->sizeELement);
                
                item->nextElement  = list->isCircle ? list->first : NULL;
                item->prevElement = list->isDoubly ? list->last : NULL;

                list->last = item;
                list->curr = item;
                list->nElements++;

                if(list->isDoubly) list->first->prevElement = list->isCircle ? list->last : NULL;

            }
        }
    }
}

bool removeLastElement(TList* list){
    if (list->nElements == 0) return false;
    
    list->curr = list->first;

    for(int i = 0; i < ((list->nElements) - 2); i++){
        list->curr = list->curr->nextElement;
    }

    TElementList* flag;

    flag = list->last;

    list->last = list->curr;
    list->curr->nextElement = list->isCircle ? list->first : NULL;
    
    if(list->isDoubly) list->first->prevElement = list->isCircle ? list->last : NULL;

    list->nElements--;

    if(list->nElements == 0){
        list->first = NULL;
        list->curr = NULL;
        list->last = NULL;
    }

    free(flag->data);
    free(flag);
}

bool removeFirstElement(TList* list){
    if (list->nElements == 0) return false;
    
    TElementList* flag;

    flag = list->first;
    list->first = list->first->nextElement;

    if(list->isDoubly) list->first->prevElement = list->isCircle ? list->last : NULL;

    list->last->nextElement = list->isCircle ? list->first : NULL;

    list->nElements--;

    if(list->nElements == 0){
        list->first = NULL;
        list->curr = NULL;
        list->last = NULL;
    }

    free(flag->data);
    free(flag);
}

bool removeCurrElement(TList* list){
    TElementList* item;
    TElementList* item2;

    if(list->nElements == 0){
        printf("Nao ha elementos na lista\n");
        return false;
    }

    if((list->curr == list->last)) return removeLastElement(list);
    if((list->curr == list->first)) return removeFirstElement(list);

    item = list->curr;

    goFirst(list);

    while(list->curr->nextElement != item){
        list->curr = list->curr->nextElement;
    }

    list->curr->nextElement = item->nextElement;

    item2 = item->nextElement;

    item2->prevElement = list->isDoubly ? list->curr : NULL;

    list->nElements--;

    free(item->data);
    free(item);
}

void dumpItem(TElementList* item, int size){
    int i;
    byte* point;
    printf("********************************\n");
    
    printf("Data = %x\n", item->data);
    printf("next = %02x\n", item->nextElement);
    printf("prev = %02x\n", item->prevElement);
    printf("Conteudo data:\n");

    point = (byte*)item->data;

    for(i = 0; i < size; i++){
        printf("%04x : %02x : %03d : %c\n", point, (*point), (*point), (*point));
        point++;
    }

    printf("********************************\n");
}

void dumpList(TList* list){
    TElementList* item;

    printf("No de elementos da lista:   %d\n",list-> nElements);
    printf("Tamanho dos elementos:      %d\n", list->sizeELement);
    printf("Ponteiro first:             %02x\n", list->first);
    printf("Ponteiro last:              %02x\n", list->last);
    printf("Ponteiro curr:              %02x\n", list->curr);
    printf("Ponteiro last->nextElement: %x\n", list->last == NULL ? NULL : list->last->nextElement);

    if(list->first != NULL){   
        item = list->first;
        for(int i = 1; i <= list->nElements + 1; i++){
            dumpItem(item, list->sizeELement);
            item = item->nextElement;
        }
    }

    printf("-------------------------------\n");
}

void showItem(TElementList* item, int position){
    printf("Lista[%d] = %d\n", position, (int)*item->data);
}

void showItems(TList* list, int numberOfElements){
    list->curr = list->first;

    for(int i = 0; i < numberOfElements; i++){
        showItem(list->curr, i);
        list->curr = list->curr->nextElement;
    }
}

bool goFirst(TList* list){
    list->curr = list->first;
}

bool goNext(TList* list){
    list->curr = !list->isCircle && (list->curr == list->last) ? NULL : list->curr->nextElement;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Tstack{
    char* buffer;
    char* first;
    char* last;
    int size;
    int sizeElement;
    int maxElement;
}stack;

bool create_stack(stack* stack, int sizeElement, int max);
void destroy_stack(stack* stack);
bool put_stack(stack* stack, char* data);
bool get_stack(stack* stack, char* data);
bool empty_stack(stack* stack);
bool full_stack(stack* stack);
int size_stack(stack* stack);
void dump_stack(stack* stack);

bool create_stack(stack* stack, int sizeElement, int max){
    if (stack == NULL) return false;

    if (sizeElement == 0 || max == 0) return false;

    if ((stack->buffer = (char*)malloc(sizeElement*max)) == NULL) return false; 

    stack->first = stack->buffer;
    stack->last = stack->buffer;

    stack->maxElement = max;
    stack->sizeElement = sizeElement;
    stack->size = 0;
}

void destroy_stack(stack* stack){
    free(stack->buffer);

    stack->size = 0;
    stack->maxElement = 0;
    stack->sizeElement = 0;

    stack->buffer = NULL;
    stack->first = NULL;
    stack->last = NULL;
}

bool put_stack(stack* stack, char* data){
    if (data == NULL) return false;

    if (stack->size < stack->maxElement){
        memcpy(stack->last, data, stack->sizeElement);
        
        stack->last += stack->sizeElement;

        stack->size++;
    }else {
        printf("ERROR: pilha cheia\n");
        return false;
    }
}

bool get_stack(stack* stack, char* data){
    if (stack->size == 0) {
        printf("ERROR: pilha vazia\n");
        return false;
    }

    memcpy(data, stack->last - stack->sizeElement, stack->sizeElement);

    stack->size--;

    if(stack->size == 0){
        stack->first = NULL;
        stack->last = NULL;
    }else{
        stack->last -= stack->sizeElement;
    }
}

bool empty_stack(stack* stack){
    return stack->size ? false : true;
}

bool full_stack(stack* stack){
    return stack->size == stack->maxElement ? true : false;
}

int size_stack(stack* stack){
    return stack->size;
}

void dump_stack(stack* fila){
    char *current,*j;
    int i;
    printf("buffer = %04x\n", fila->buffer);
    printf("SizeElem = %d\n",fila->sizeElement);
    printf("Size     = %d\n",fila->size);
    printf("Max      = %d\n",fila->maxElement);
    printf("first  = %04x\n",fila->first);
    printf("Last   = %04x\n",fila->last);
    printf("-----------------------\n");
    current = fila->first;
    for( i =0; i< fila->size;i++){
        printf("Elemento [%d]\n",i);
        for(j=current; j < current + fila->sizeElement;j++){
            printf("%04x : %02x\n",j,(*j));
        }
        current += fila->sizeElement;
        if(current>= fila->buffer + fila->maxElement*fila->sizeElement)
           current = fila->buffer;
        printf("-----------------------\n");
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Tfila{
    char* buffer;
    char* first;
    char* last;
    int size;
    int sizeElement;
    int maxElement;
}stack;

bool create(stack* stack, int sizeElement, int max);
void destroy(stack* stack);
bool put(stack* stack, char* data);
bool get(stack* stack, char* data);
bool empty(stack* stack);
bool full(stack* stack);
int size(stack* stack);
void dump(stack* stack);

int main(){
    stack stack;

    create(&stack, sizeof(int), 5);

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;

    put(&stack, &a);
    put(&stack, &b);
    put(&stack, &c);
    put(&stack, &d);
    put(&stack, &e);

    int x;
    get(&stack, &x);
    get(&stack, &x);
    get(&stack, &x);
    get(&stack, &x);
    get(&stack, &x);
    printf("%d\n", x);
    printf("%s\n", empty(&stack) ? "Yes" : "No");
}

bool create(stack* stack, int sizeElement, int max){
    if (stack == NULL) return false;

    if (sizeElement == 0 || max == 0) return false;

    if ((stack->buffer = malloc(sizeElement*max)) == NULL) return false; 

    stack->first = stack->buffer;
    stack->last = stack->buffer;

    stack->maxElement = max;
    stack->sizeElement = sizeElement;
    stack->size = 0;
}

void destroy(stack* stack){
    free(stack->buffer);

    stack->size = 0;
    stack->maxElement = 0;
    stack->sizeElement = 0;

    stack->buffer = NULL;
    stack->first = NULL;
    stack->last = NULL;
}

bool put(stack* stack, char* data){
    if (data == NULL) return false;

    if (stack->size < stack->maxElement){
        memcpy(stack->last, data, stack->sizeElement);
        
        stack->last += stack->sizeElement;

        stack->size++;
    }else {
        printf("ERROR: fila cheia\n");
        return false;
    }
}

bool get(stack* stack, char* data){
    if (stack->size == 0) {
        printf("ERROR: fila vazia\n");
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

bool empty(stack* stack){
    return stack->size ? false : true;
}

bool full(stack* stack){
    return stack->size == stack->maxElement ? true : false;
}

int size(stack* stack){
    return stack->size;
}

void dump(stack* fila){
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

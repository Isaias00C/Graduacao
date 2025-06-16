#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Tqueue{
    char* buffer;
    char* first;
    char* last;
    int size;
    int sizeElement;
    int maxElement;
}queue;

bool create_queue(queue* queue, int sizeElement, int max);
void destroy_queue(queue* queue);
bool put_queue(queue* queue, char* data);
bool get_queue(queue* queue, char* data);
bool empty_queue(queue* queue);
bool full_queue(queue* queue);
int size_queue(queue* queue);
void dump_queue(queue* queue);

bool create_queue(queue* queue, int sizeElement, int max){
    if (queue == NULL) return false;

    if (sizeElement == 0 || max == 0) return false;
    
    if ((queue->buffer = (char*)malloc(sizeElement*max)) == NULL) return false; 

    queue->first = queue->buffer;
    queue->last = queue->buffer;

    queue->maxElement = max;
    queue->sizeElement = sizeElement;
    queue->size = 0;
}

void destroy_queue(queue* queue){
    free(queue->buffer);

    queue->size = 0;
    queue->maxElement = 0;
    queue->sizeElement = 0;

    queue->buffer = NULL;
    queue->first = NULL;
    queue->last = NULL;
}

bool put_queue(queue* queue, char* data){
    if (data == NULL) return false;
    
    if (queue->size < queue->maxElement){
        memcpy(queue->last, data, queue->sizeElement);
        
        queue->last += queue->sizeElement;

        if (queue->last >= queue->buffer + queue->sizeElement*queue->maxElement) queue->last = queue->buffer;

        queue->size++;
    }else {
        printf("ERROR: fila cheia\n");
        return false;
    }
}

bool get_queue(queue* queue, char* data){
    if (queue->size == 0) {
        printf("ERROR: fila vazia\n");
        return false;
    }

    memcpy(data, queue->first, queue->sizeElement);

    queue->size--;

    if(queue->size == 0){
        queue->first = NULL;
        queue->last = NULL;
    }else{
        queue->first += queue->sizeElement;
        
        if(queue->first >= queue->buffer + queue->maxElement*queue->sizeElement) queue->first = queue->first;
    }
}

bool empty_queue(queue* queue){
    return queue->size ? false : true;
}

bool full_queue(queue* queue){
    return queue->size == queue->maxElement ? true : false;
}

int size_queue(queue* queue){
    return queue->size;
}

void dump_queue(queue* fila){
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
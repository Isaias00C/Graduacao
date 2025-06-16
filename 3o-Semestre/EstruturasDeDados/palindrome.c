#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "stack.h"
#include <locale.h>

int main(){
    int size;

    printf("Qual o tamanho da palavra: ");
    scanf("%d", &size);

    char *word = malloc(sizeof(char) * size);

    if(word == NULL) {
        printf("ERROR: malloc não funcionou\n");
        return 0;
    }

    printf("Qual é a palavra: ");
    scanf("%s", word);

    stack stack;
    queue queue;

    create_stack(&stack, sizeof(char), size);
    create_queue(&queue, sizeof(char), size);

    for(int i = 0; i < size; ++i){
        printf("%c ", word[i]); 
        put_stack(&stack, &word[i]);
        put_queue(&queue, &word[i]);
    }
    printf("\n");

    bool isPalindrome = true;

    for(int i = 0; i < size; ++i){
        char lastStack, firstQueue;
        get_stack(&stack, &lastStack);
        get_queue(&queue, &firstQueue);

        if(firstQueue != lastStack) isPalindrome = false;
    }

    printf("%s", isPalindrome ? "sim, é palindromo\n" : "Não, é palindromo\n");

    destroy_stack(&stack);
    destroy_queue(&queue);

    free(word);

    return 0;
}
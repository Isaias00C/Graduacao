#include <stdio.h>
#include "stack.h"

void StackSort(stack* _stack);
void Sort(stack* _stack, stack* sortedStack);

int main(){
    stack stack;

    create_stack(&stack, sizeof(char), 5);

    char a = 2;
    char b = 3;
    char c = 5;
    char d = 4;
    char e = 1;

    put_stack(&stack, &a);
    put_stack(&stack, &b);
    put_stack(&stack, &c);
    put_stack(&stack, &d);
    put_stack(&stack, &e);

    StackSort(&stack);

    int size = (&stack)->size;
    for(char i = 0; i < size; ++i){
        char x;
        get_stack((&stack), &x);
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}

void StackSort(stack* _stack){
    stack auxStack;

    create_stack(&auxStack, _stack->sizeElement, _stack->maxElement);

    Sort(_stack, &auxStack);

    destroy_stack(&auxStack);
}

void Sort(stack* _stack, stack* sortedStack){
    int size = _stack->size;
    for(int i = 0; i < size; ++i){
        int val;
        get_stack(_stack, &val);
        put_stack(sortedStack, &val);
    }
    
    while(sortedStack->size != 0){
        char top;
        get_stack(sortedStack, &top);

        if(_stack->size != 0){
            char top_sorted;
            get_stack(_stack, &top_sorted);

            if(top_sorted > top){
                put_stack(_stack, &top_sorted);
                put_stack(_stack, &top);
            }else{
                put_stack(sortedStack, &top_sorted);
                put_stack(sortedStack, &top);
            }
        }else put_stack(_stack, &top);
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;

void showDumpMemory(char *address, int size){
    int i;
    byte *point;
    point = address;
    printf("Dump da memoria\n");
    for(i = 0; i < size; i++){
        printf("%04x : %02x\n", point, *point);
        point++;
    }
}

int main(){
    int a, b;
    int *p_a;

    a = 20;
    printf("a = %d &a = %x p = %x\n", a, &a, p_a);
    p_a = &a;
    printf("a = %d &a = %x p = %x\n", a,  &a, p_a);
    
    showDumpMemory(&a, sizeof(a));
    memset(p_a, 0x03, 2);
    showDumpMemory(&a, sizeof(a));
    
    printf("a = %d &a = %x p = %x\n", a, &a, p_a);
    memcpy(&b, &a, sizeof(a));
    printf("a = %d &a = %x p = %x\n", a, &a, p_a);
    
    showDumpMemory(&b, sizeof(b));
    memset(&a, 0x02, 5);
    showDumpMemory(&b, sizeof(b));
    
    byte *p;
    byte *pc;
    if((p = malloc(10)) == NULL){
        printf("Memoria insuficiente!\n");
        return -1;
    }
    
    printf("Dump de p = %x\n", p);
    showDumpMemory(p, 50);

    memset(p, 0x00, 50);
    memset(p, 0x01, 10);
    memset(p+20, 0x02, 10);
    
    printf("Dump de p = %x\n", p);
    showDumpMemory(p, 50);
    
    pc = p;
    free(p);
    
    printf("Dump de pc = %x\n");
    showDumpMemory(pc, 50);
    
    
    
    return 0;
}
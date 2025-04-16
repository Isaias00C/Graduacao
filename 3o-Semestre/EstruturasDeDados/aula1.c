#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, i;
    char *p;
    a = 745;
    p = &a;

    for(i = 0; i < sizeof(int); i++){
        printf("%x : %02x\n", p, (unsigned char)(*p));
        p++;
    }
    return 0;
}
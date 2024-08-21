void v1(){
    int A[6] = {1, 0, 5, -2, -5, 7};

    int s = A[0] + A[1] + A[5];

    A[4] = 100;

    for(int i = 0; i < 6; i++){
        printf("%d\n", &A[i]);
    }

}

void v2(){
    int v[6];

    for(int i = 0; i < 6; i++) scanf("%d", &v[i]);
    for(int i = 0; i < 6; i++) printf("%d ", v[i]);
}

void v3(){
    double n[10], q[10];

    int i;
    for(i = 0; i < 10; i++) scanf("%.2lf", &n[i]), q[i] = n[i]*n[i];
    for(i = 0; i < 10; i++) printf("%.2lf ", q[i]);
}

void v4(){
    int v[8];
    int x, y;

    for(int i = 0; i < 10; i++) scanf("%d", &v[i]);
    for(int i = x - 1; i < y; i++) printf("%d ", v[i]);

}

void v5(){
    int v[10], c = 0; 

    for(int i = 0; i < 10; i++){
        if(v[i] % 2 == 0) c++;
    }

    
}

void v6(){
    int v[10];

    for(int i = 0; i < 10; i++) scanf("%d", &v[i]);

    int max = v[0], min = v[0];
    for(int i = 1; i < 10; i++){
        max = max > v[i] ? max : v[i];
        min = min < v[i] ? min : v[i];
    }   

    printf("%d %d", max, min);
    
}

void v7(){
    int v[10], max = 0, index;
    for(int i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
        max = max > v[i] ? max : v[i], index = i;
    }

    printf("%d %d");
}

void v8(){
    int v[6];
    
    for(int i = 0; i < 6; i++) scanf("%d", &v[i]);
    for(int i = 5; i >= 0; i++) printf("%d ", v[i]);
}

void v9(){
    int v[6];
    
    for(int i = 0; i < 6; i++) scanf("%d", &v[i]);
    for(int i = 5; i >= 0; i++) printf("%d ", v[i]);    
}

void v10(){
    double v[15];
    double media = 0;

    for(int i = 0; i < 15; i++) scanf("%lf", &v[i]), media+=v[i];
    printf("%.2lf", media / (float)15);
}

void v11(){
    int v[10], qtd = 0, soma = 0;

    for(int i = 0; i < 10; i++){
        scanf("%d", &v[i]);
        if(v[i] >= 0) soma += v[i];
        else qtd++;
    }

    printf("%d %d", qtd, soma);
}

void v12(){
    int v[5];
    for(int i = 0; i < 5; i++){
        
    }
}

int main(){}

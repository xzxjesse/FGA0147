#include <stdio.h>

int main() {
    int L, D, K, P;
    
    scanf("%d %d", &L, &D);
    scanf("%d %d", &K, &P);
    
    int custoTotal = ((L/D) * P) + L *K;
    
    printf("%d\n", custoTotal);
    
    return 0;
}
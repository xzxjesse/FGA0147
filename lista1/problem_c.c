#include <stdio.h>
#include <stdlib.h>

int main() {
    int xMaria, yMaria, xReuniao, yReuniao;
    int cruzamentos;

    scanf("%d %d %d %d", &xMaria, &yMaria, &xReuniao, &yReuniao);
    
    if (xMaria>=0 && yMaria<=1000 && xReuniao>=0 && yReuniao<=1000){

        if (xMaria == xReuniao){
            cruzamentos = abs(yMaria - yReuniao);
        } else if (yMaria == yReuniao){
            cruzamentos = abs(xMaria - xReuniao);
        } else{
            cruzamentos = abs(yMaria - yReuniao) + abs(xMaria - xReuniao);
        }

    }
    
    printf("%d\n", cruzamentos);
    
    return 0;
}
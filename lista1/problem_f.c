#include <stdio.h>

int main (){

    int cartas[5];
    int i;
    int decrescente = 1;
    int crescente = 1;

    for(i=0; i<5; i++){
        scanf("%d", &cartas[i]);

        if(cartas[i]<1 || cartas[i]>13){
            return 1;
        }
        
    }

    for(i=1;i<5;i++){
        if (cartas[i]>cartas[i-1]){
            decrescente=0;
        }else if (cartas[i]<cartas[i-1]){
            crescente=0;
        }
    }

    if(crescente){
        printf("C");
    }else if(decrescente){
        printf("D");
    }else{
        printf("N");
    }

    return 0;
}
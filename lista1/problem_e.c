#include <stdio.h>

int main (){

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if(a==b && b==c){
        printf("empate");
    }else if (a==b && b!=c){
        printf("C");
    }else if (a==c && c!=b){
        printf("B");
    }else{
        printf("A");
    }

    return 0;
}
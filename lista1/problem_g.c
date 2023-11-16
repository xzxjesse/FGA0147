#include <stdio.h>

int main (){

    double a, g, ra, rg, aa, gg;

    scanf("%lf %lf %lf %lf", &a, &g, &ra, &rg);

    if (a<0.01||a>10.00||g<0.01||g>10.00||ra<0.01||ra>20.00||rg<0.01||rg>20.00){
        return 1;
    }
    
    aa = a/ra;
    gg = g/rg;

    if(gg>aa){
        printf("A");
    }else if(aa>gg||aa==gg){
        printf("G");
    }

    return 0;
}
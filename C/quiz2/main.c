#include <stdio.h>
#include <stdlib.h>

int disc,a,b,c;

void main()
{
    printf("ax^2+bx+c seklinde denklem icin a,b,c degerlerini giriniz:\n");
    scanf("%d%d%d",&a,&b,&c);
    disc= (b*b)-(4*a*c);
    if(disc>0){
        printf("2 kok var");
        }
    else if(disc == 0){
        printf("1 kok var");
    }
    else{
        printf("kok yok");
    }
}

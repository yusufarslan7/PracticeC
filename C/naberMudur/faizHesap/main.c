#include <stdio.h>
#include <stdlib.h>

int main()
{
    float anapara=0,faiz=0,gun=0;
    while(1){
        printf("Anaparayi girin (cikis -1): ");
        if (anapara==-1) break;
        scanf("%f",&anapara);
        fflush(stdin);
        printf("Yillik faiz oranini girin: ");
        scanf("%f",&faiz);
        fflush(stdin);
        printf("Kac gunluk faiz: ");
        scanf("%f",&gun);
        fflush(stdin);
        printf("faiz ucreti %.2f$dir.",anapara*faiz*gun/365);
    }
    return 0;
}

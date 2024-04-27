#include <stdio.h>
#include <stdlib.h>

int main()
{
    float dolar;
    while (1){
        printf("Kazanci $ cinsinden giriniz(-1 cikis): ");
        scanf("%f",&dolar);
        if(dolar==-1) break;
        printf("\nMaas: %.2f$\n\n",dolar*9/100);
    }
    return 0;
}

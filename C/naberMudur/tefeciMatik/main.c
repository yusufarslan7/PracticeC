#include <stdio.h>
#include <stdlib.h>

int main()
{
    float faiz,borc;
    printf("Borc giriniz: ");
    scanf("%f",&borc);
    printf("Yuzdelik faiz giriniz: ");
    scanf("%f",&faiz);
    for(int i=0;i<12;i++){
        borc*= (faiz+100)/100;
        printf("\n%d ay sonraki borc: %f\n",i+1,borc);
    }
    return 0;
}

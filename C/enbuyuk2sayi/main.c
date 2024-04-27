#include <stdio.h>
#include <stdlib.h>

int main()
{
    int enBuyuk1=0,enBuyuk2=0,sayi=0;
    for(int i=0;i<10;i++){
        printf("%d. sayiyi giriniz: ",i+1);
        scanf("%d",&sayi);
        fflush(stdin);
        if(sayi>=enBuyuk1){
            enBuyuk1=sayi;
        }
        else if(sayi>enBuyuk2){
            enBuyuk2=sayi;
        }
    }
    printf("En buyuk sayi1: %d\nEn buyuk sayi2: %d",enBuyuk1,enBuyuk2);
    return 0;
}

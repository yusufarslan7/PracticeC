#include <stdio.h>
#include <stdlib.h>

int main()
{   int sayilar[5];
    printf("1-30 arasinda 5 sayi giriniz: ");
    scanf("%d %d %d %d %d",&sayilar[0],&sayilar[1],&sayilar[2],&sayilar[3],&sayilar[4]);
    for(int i=0;i<5;i++){
        for (int b=0;b<sayilar[i];b++){
            printf("*");
        }
    printf("\n");
    }
    return 0;
}

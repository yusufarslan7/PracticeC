#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int a=0,b=0,m=0,kucuk=0,buyuk=0,mod=0,toplam=0;

    do{
    printf("1 ile 100 arasinda iki sayi giriniz.\nbirinci sayi: ");
    scanf("%d",&a);
    printf("ikinci sayi: ");
    scanf("%d",&b);}
    while((a<1 || a>100) || (b<1 || b>100));

    printf("Mod degerini giriniz (Mumkunse 0 olmasin kontrol etme demisler de): ");
    scanf("%d",&m);
    printf("\n\n");

    if(a<b){
        kucuk=a;
        buyuk=b;
    }
    else{
        kucuk=b;
        buyuk=a;
    }
    for(int i=kucuk;i<=b;i++){
        mod=i%m;
        printf("(%dx%d) + ",i,mod);
        toplam+=i*mod;
    }
    printf("\b\b \nToplam sonuc: %d",toplam);
}

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int sayi=0,toplam=0;
    while(sayi<=9){
        toplam += ++sayi;
    }
    printf("%d",toplam);
}

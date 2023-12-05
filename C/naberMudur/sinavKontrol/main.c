#include <stdio.h>
#include <stdlib.h>

int main()
{
    int not,gecenler=0,sayi=0;
    while(sayi<10){
        printf("%d. degeri giriniz(1 gecti / 2 kaldi): ",sayi+1);
        scanf("%d",&not);
        if(not==1){
            gecenler++;
        }
        sayi++;
    }
    printf("gecen kisi sayisi: %d\nKalan kisi sayisi: %d\n",gecenler,10-gecenler);
    if(gecenler>8) printf("Ustun basari!");
    return 0;
}

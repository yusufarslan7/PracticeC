#include <stdio.h>
#include <stdlib.h>


void xParseSeconds(int seconds){
    printf("%d saat %d dakika %d saniye\n- - - - - - - - - - - - - - - - - - - - ",seconds/3600,seconds%3600/60,seconds%60);
}


void main()
{   int saniye;
    printf("Saniye bilgisi giriniz: ");
    scanf("%d",&saniye);
    xParseSeconds(saniye);
}


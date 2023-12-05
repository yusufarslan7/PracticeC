#include <stdio.h>
#include <stdlib.h>
#include <math.h>>


int main()
{   float anapara=0,faiz=0,yil=0;
    printf("anapara gir: ");
    scanf("%f",&anapara);
    printf("faiz gir: ");
    scanf("%f",&faiz);
    printf("yil gir: ");
    scanf("%f",&yil);
    for(int i=0;i<yil;i++){
        anapara *= (100+faiz)/100;
    }
    printf("%f",anapara);
    return 0;
}

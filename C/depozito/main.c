#include <stdio.h>
#include <stdlib.h>

int main()
{
    int yil;
    double miktar=0,anapara=1000.0,oran=0.05;
    printf("%4s%21s\n","Yil","Depozito Miktari");

    for(yil=1;yil<=10;yil++){
    miktar= anapara*pow(1.0+oran,yil);
    printf("%3d%21.2f\n",yil,miktar);
    }

    printf("press any key to quit...");
    getchar();
    return 0;
}

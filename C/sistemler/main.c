#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int oct[3],hex[2];
    char bin[8];
    for(int i=0;i<256;i++){
           int b=i;
           int c=i;
        for(int a=7;a>=0;a--){
            if(b-pow(2,a)>=0){
                b-=pow(2,a);
                bin[7-a]='1';
            }
            else{
                bin[7-a]='0';
            }
        }
    for(int a=2;a>=0;a--){
        if(c-pow(8,a)>=0){
            oct[2-a]=c/pow(8,a);
            c-=oct[2-a]*pow(8,a);

        }
        else {
            oct[2-a]=0;
        }
    }
    printf("Binary: %s\tOctal: %d%d%d\tDecimal: %d\tHexadecimal: %X\n",bin,oct[0],oct[1],oct[2],i,i);
    }
    printf("Kapatmak icin ENTER tusuna basiniz...");
    fflush(stdin);
    getchar();
    return 0;

}

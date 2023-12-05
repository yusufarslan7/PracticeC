#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,trigger=0;

    etiket:
    do{
        trigger == 0 ? printf("%d\n",i++):printf("%d\n",i--);
    }while(i<9 && i>=0);

    if(trigger==0){
        trigger++;
        goto etiket;}
    return 0;
}

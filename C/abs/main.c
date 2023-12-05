#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    printf("Tek sayi uzunluk gir: ");
    scanf("%d",&i);
    fflush(stdin);
    if(i%2){
    for(int a=0;a<=i;a+=2){
        for(int b=(i-a)/2;b>0;b--){
            printf(" ");
        }
        for(int b=-1;b<a;b++){
            printf("*");
        }
        printf("\n");
    }
    for(int a=0;a<i-2;a+=2){
        for(int b=-1;b<a;b+=2){
            printf(" ");
        }
        for(int b=0;b<(i-2)-a;b++){


            printf("*");
        }
        printf("\n");
    }
    printf("cikmak icin ENTER tusuna bas...");
    getchar();
    }
    else{
        printf("\n\nTEK OLACAK DIYOM!\n\n");
        main();
    }
    return 0;

}

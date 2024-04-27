#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b=0;
    printf("Kare kenari giriniz: ");
    scanf("%d",&b);
    fflush(stdin);
    for(int i=0;i<b;i++){
        printf("*");
    }
        for(int c=0;c<b-2;c++){
            printf("\n*");
            for(int d=0;d<b-2;d++){
                printf(" ");
            }
            printf("*");
        }
    printf("\n");
    for(int i=0;i<b;i++){
        printf("*");
        }
    return 0;
}

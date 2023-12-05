#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=2,sayi=0,carpan1=0,carpan2=0,carpan3=0,sayitest=0,kac1=0,kac2=0,kac3=0,flag=0,asaltrigger=0;
    printf("Sayi giriniz: ");
    scanf("%d",&sayi);
    sayitest=sayi;
    printf("Asal carpanlar: ");
    while(sayitest!= 1){

        if(sayitest%i==0){
            sayitest/=i;
            flag++;
            if(carpan1!=i){
                asaltrigger=1;
                carpan3=carpan2;
                carpan2=carpan1;
                carpan1=i;
                printf("%d, ",i);
            }
        if(sayitest %i==0){
                continue;
        }
        }
        if (asaltrigger==1){
            kac3=kac2;
            kac2=kac1;
            kac1=flag;
            flag=0;
            asaltrigger=0;
        }

        i++;
    }
    printf("\b\b \n\nEn buyuk asal carpanlar: \n%d-> %d\n%d-> %d\n%d-> %d", carpan1,kac1,carpan2,kac2,carpan3,kac3);
    return 0;
}

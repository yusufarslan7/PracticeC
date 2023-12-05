#include <stdio.h>
#include <stdlib.h>

unsigned long long int faktoriyel(int);

int main()
{
    int sayi=0;

    printf("sayi girin: ");
    scanf("%d",&sayi);

    for(int i=1,b=1,c=2;i<=(sayi*(sayi+1))/2;i++){
        printf("*");
        if(i%b==0){
            printf("\n");
            b+=c;
            c++;
        }
    }
    return 0;
}
/*unsigned long long int faktoriyel(int a)
{
    unsigned long long int cevap=1;

    for(int i=1;i<=a;i++){
        cevap*=i;
    }
    return cevap;
}*/

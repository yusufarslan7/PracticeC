#include <stdio.h>
#include <stdlib.h>

unsigned long long int faktoriyel(unsigned long long int);

int main()
{
    unsigned long long int number=0;
    printf("sayi gir: ");
    scanf("%d",&number);
    printf("%lld faktoriyel == %llu\n",number,faktoriyel(number));

    return 0;
}

unsigned long long int faktoriyel(unsigned long long int sayi)
{
    if (sayi<=1){
        return 1;
    }
    else{
        return (sayi*faktoriyel(sayi-1));
    }
}

#include <stdio.h>
#include <stdlib.h>

long fibonacci(long);

int main()
{   int sayi=0;

    printf("sayi gir: ");
    scanf("%d",&sayi);
    printf("fibonacci %d. basamak: %ld",sayi,fibonacci(sayi));

    return 0;
}

long fibonacci(long number){

    if(number==0) return 0;
    else if (number==1) return 1;
    else return (fibonacci(number-1)+fibonacci(number-2));

}

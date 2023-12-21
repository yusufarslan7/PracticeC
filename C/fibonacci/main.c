#include <stdio.h>
#include <stdlib.h>

double fibonacci(double);

int main()
{
    int sayi=0;

    printf("Bir tamsayi giriniz: ");
    scanf("%d",&sayi);
    printf("Fibonacci %d.basamak: %.lf",sayi,fibonacci(sayi));
    return 0;
}

double fibonacci(double a)
{
    if(a==0){
        return 0;
    }
    else if(a==1 || a==2){
        return 1;
    }
    else{
        return (fibonacci(a-1)+fibonacci(a-2));
    }
}

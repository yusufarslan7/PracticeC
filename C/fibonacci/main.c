#include <stdio.h>
#include <stdlib.h>

long fibonacci(long);

int main()
{
    int sayi=0;

    printf("Bir tamsayi giriniz: ");
    scanf("%d",&sayi);
    printf("Fibonacci %d.basamak: %ld",sayi,fibonacci(sayi));
    return 0;
}

long fibonacci(long a)
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

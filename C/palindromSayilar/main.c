#include <stdio.h>
#include <stdlib.h>

int sayiTers(int);

int main()
{
    int a=0;
    printf("Sayi giriniz: ");
    scanf("%d", &a);
    if(a==sayiTers(a))
        printf("Sayi palindromdur.");
    else
        printf("Sayi palindrom degildir.");
    return 0;
}

sayiTers(int sayi)
{
    int s=0;

    while(sayi>0)
    {
        s=s*10+sayi%10;
        sayi/=10;
    }
    return s;
}

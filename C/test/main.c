#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int sayi=0,asalmi=1;
    printf("Sayi gir: ");
    scanf("%d",&sayi);
    printf("\nAsal sayilar: ");

    for(int i=2;i<=sayi;i++)
    {
        for(int j=2;j<sqrt(i);j++)
        {
            asalmi=0;
            if(i%j==0)
            {
                asalmi=1;
                break;
            }
        }
        if(asalmi==0 || i==2)
        {
            printf("%d, ",i);
        }
    }
    printf("\b\b ");
    return 0;
}

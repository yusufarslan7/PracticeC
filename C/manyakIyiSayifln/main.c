#include <stdio.h>
#include <stdlib.h>

int muk(int);

int main()
{
    int a=0;
    for(a=0;a<=1000;a++)
    {
        if(muk(a))
        {
            printf("%d evt\n\n",a);
        }
        else
        {
            printf("%d yok diyen ghost rider\n\n",a);
        }
    }
        return 0;
}

int muk(sayi)
{
    int toplam=0;
    for(int i=1;i<sayi;i++)
    {
        if(sayi%i==0)
        {
            toplam+=i;
        }
    }
    if(toplam==sayi)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

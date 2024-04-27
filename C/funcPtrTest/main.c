#include <stdio.h>
#include <stdlib.h>




int main()
{
    void sirala(int *,const int,int (*)(const int,const int));
    int artan(const int,const int);
    int azalan(const int,const int);

    int a[10]={7,123,23,1,634,423,455,429,645,7567};
    int secim=0;
    printf("artan sira icin 1, azalan sira icin 2'yi tuslayiniz: ");
    scanf("%d",&secim);
    if(secim==1)
    {
        sirala(a,10,artan);
    }
    else if(secim==2)
    {
       sirala(a,10,azalan);
    }
    else
    {
        printf("hatali giris.");
    }
    for(int i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }

    return 0;
}

void sirala(int *dizi,int boyut,int (*naberMudur)(int a,int b))
{
    void degistir(int*,int*);

    for(int tur=1;tur<boyut;tur++)
    {
        for(int sayici=0;sayici<boyut-1;sayici++)
        {
            if((*naberMudur)(*(dizi+sayici),*(dizi+sayici+1)))
               {
                    degistir(dizi+sayici,dizi+sayici+1);
               }

        }
    }
}

int artan(const int a,const int b)
{
    return b<a;
}

int azalan(const int a,const int b)
{
    return a<b;
}

void degistir(int* a,int* b)
{
    int gecici=*b;
    *b=*a;
    *a=gecici;

}

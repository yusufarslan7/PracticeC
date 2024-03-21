#include <stdio.h>
#include <stdlib.h>
void diziYazdir(int *,int []);
void diziGir(int[],int *);

int main()
{
    int boyut=0;
    int *p;
    int temp=0;
    p=&boyut;

    printf("Dizi boyutu seciniz:");
    scanf("%d",p);

    int dizi1[boyut],dizi2[boyut],diziB[2][boyut],diziT[boyut*2];
    diziGir(dizi1,p);
    diziGir(dizi2,p);

    for(int i=0;i<boyut;i++)
    {
        diziT[i]=dizi1[i];
    }

    for(int i=boyut;i<boyut*2;i++)
    {
        diziT[i]=dizi2[i-boyut];
    }

    for(int i=0;i<(boyut*2)-1;i++)
    {
        for(int j=0;j<(boyut*2)-1;j++)
        {
            if(diziT[j]<diziT[j+1])
            {
                temp = diziT[j];
                diziT[j]=diziT[j+1];
                diziT[j+1]=temp;
            }
        }
    }
    for(int i=0; i<boyut;i++)
    {
        diziB[0][i]=diziT[i];
    }
    for(int i=0; i<boyut;i++)
    {
        diziB[1][i]=diziT[boyut+i];
    }

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<*p;j++)
        {
            printf("%5d ", diziB[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void diziGir(int a[],int *p)
{
    etiket:
    for(int i=0;i<*p;i++)
    {
        printf("Dizinin %d. elemanini giriniz: ", i+1);

        if(scanf("%d",&a[i])==0)
        {
            fflush(stdin);
            printf("\ntam sayi girmelisiniz.\n");
            goto etiket;
        }
    }

}

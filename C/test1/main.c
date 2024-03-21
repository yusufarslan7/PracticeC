#include <stdio.h>
int main()
{
    int p[4]={0};
    void fonk(int,int[],int[]);
    int dizi[]={1,2,3,4};
    int i;
    fonk(4, dizi, p);
    for(i=0;i<4;i++)
    {
        printf("%d,",p[i]);
    }
    return 0;
}
void fonk(int n,int dizi[],int p[])
{

    int i=0;
    while(i<n)
    {
        p[i]=dizi[i]%2;
        i++;
    }
}

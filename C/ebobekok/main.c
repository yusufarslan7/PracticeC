#include <stdio.h>
#include <stdlib.h>

int ebob(int,int);

int main()
{
    int a=0,b=0;
    printf("2 sayi giriniz: ");
    scanf("%d %d",&a,&b);
    printf("ebob= %d\nekok= %d",ebob(a,b),a*b/ebob(a,b));
    return 0;
}

int ebob(a,b)
{
    int s=0;
    for(int i=1;i<=a&&i<=b;i++)
    {
        if(a%i==0&&b%i==0)
            s=i;
    }
    return s;
}

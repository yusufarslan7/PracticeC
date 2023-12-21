#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int a=rand(),a2=a,c=0,a3=a;

    while(a2/10!=0)
    {
        a2/=10;
        c++;
    }

    for(int i=0;i<=c;i++)
    {
        a3=a;
        for(int j=i ; j<c ; j++)
        {
            a3/=10;
        }
        printf("%d  ",a3%10);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    if(scanf("%d",&a)){

    for(int i=0;i<a;i++)
    {
        for(int j=0;j<i;j++)
        {
            printf(" ");
        }
        for(int j=0;j<a-i;j++)
        {
            printf("*");
        }
    printf("\n");
    }
    }
    else printf("31");
    return 0;
}

 /*for(int i=1;i<=4;i++)
    {
        for(int j=0;j<i;j++)
        {
            printf("*");
        }
    printf("\n");
    }
*/

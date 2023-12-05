#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,j=0;
    printf("sekil secin secin: ");
    scanf("%d",&i);
    printf("Boyut secin: ");
    scanf("%d",&j);
    switch(i)
    {
    case 1:
        ucgen(j);
        break;
    case 2:
        gemi(j);
        break;
    case 3:
        cizgiler(j);
        break;
    }
    return 0;
}

int gemi(int a)
{
    for(int i=1;i<=a;i++)
    {
        for(int j=3*a;j>i;j--)
        {
            printf(" ");
        }
        for(int j=0;j<i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a*3-i*2;j++)
        {
            printf("* ");
        }
        printf("\n");
        for(int j=a-i;j<=a;j++)
        {
            printf("  ");
        }
    }

}

int ucgen(int a)
{
    for(int i=1;i<=a;i++)
    {
        for(int j=a;j>i;j--)
        {
            printf(" ");
        }
        for(int j=0;j<i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int cizgiler(int a)
{
    for(int y=a;y>=-a;y--)
    {
        for(int x=-a;x<=a;x++)
        {
            if(x==0)
            {
             printf("* ");
            }
            else if(((float)y/x==-1 || (float)y/x==1 || (float)y/x==0)&& ((float)x*x + (float)y*y < a*a))
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

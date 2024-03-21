#include <stdio.h>
#include <stdlib.h>

void diziTest(int,int [0][0][0]);

int main()
{
    int b[20][20][20]={{0},{0}};

    diziTest(20,b);
    return 0;
}

void diziTest(int boy,int a[boy][boy][boy])
{
    for(int i=0;i<boy;i++)
    {
        for(int j=0;j<boy;j++)
        {
            for(int k=0;k<boy;k++)
            {
                printf("%d ",a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

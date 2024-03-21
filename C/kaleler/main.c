#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOYUT 8

void kaleler(int[BOYUT][BOYUT]);

int main()
{
    srand(time(0));
    int kale[BOYUT][BOYUT]={};
    printf("Kale yerlesimi:\n\n");
    kaleler(kale);

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("%d ",kale[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void kaleler(int tahta[BOYUT][BOYUT])
{
    int secilenkare[2];

    for(int kale_count=1;kale_count<=8;kale_count++)
    {
        secilenkare[0]=rand()%8;
        secilenkare[1]=rand()%8;
        if(tahta[secilenkare[0]][secilenkare[1]]==0)
        {
            tahta[secilenkare[0]][secilenkare[1]]=8;
            for(int i=secilenkare[0]+1;i<8;i++)
            {
                tahta[i][secilenkare[1]]=1;
            }
             for(int i=secilenkare[0]-1;i>-1;i--)
            {
                tahta[i][secilenkare[1]]=1;
            }
            for(int i=secilenkare[1]-1;i>-1;i--)
            {
                tahta[secilenkare[0]][i]=1;
            }
            for(int i=secilenkare[1]+1;i<8;i++)
            {
                tahta[secilenkare[0]][i]=1;
            }
            continue;
        }
        else
        {
            kale_count--;
        }
    }
}


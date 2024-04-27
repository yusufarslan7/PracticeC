#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void kar(int [4][13]);
void dagit(const int [4][13]);

int main()
{
    int deste[4][13]={0};
    srand(time(0));
    kar(deste);
    dagit(deste);

    return 0;
}

kar(int d[4][13])
{
    int satir=0,sutun=0;
    for(int kart=1;kart<=52;kart++)
    {
        do{
        satir=rand()%4;
        sutun=rand()%13;
        }while(d[satir][sutun]!=0);
        d[satir][sutun]=kart;
    }
}

dagit(const int d[4][13])
{
    const char* takim[4]={"Kupa","Karo","Sinek","Maca"};
    const char* taraf[13]={"As","Iki","Uc","Dort","Bes","Alti","Yedi","Sekiz","Dokuz","On","Vale","Kiz","Papaz"};
    int kart=1;

        etiket:
        for(int satir=0;satir<4;satir++)
        {
            for(int sutun=0;sutun<13;sutun++)
            {
                if(d[satir][sutun]==kart)
                {
                    printf("%-5s %-8s%c",takim[satir],taraf[sutun],kart%2==0 ? '\n':'\t');
                    kart++;
                    if(kart<53)goto etiket;
                    return;
                }
            }
        }
}

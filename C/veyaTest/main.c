#include <stdio.h>
#include <stdlib.h>

int main()
{
    int kemer=0,bebek=0,hava=0,zaman=0,hiz=0,lim=90;
    printf("Gir ya Ali(kemer bebek hava zaman hiz): ");
    scanf("%d %d %d %d %d",&kemer,&bebek,&hava,&zaman,&hiz);
    if(kemer==1){
        for(int i=0;i<3 && lim==90 ;i++){
            switch(i){
                case 0:
                    if(bebek==1){
                        lim-=30;
                    }
                    break;
                case 1:
                    if(hava!=1){
                        lim-=20;
                    }
                    break;
                case 2:
                    if(zaman==0){
                        lim-=10;
                    }
                    break;
            }
        }
    }
    else{
        printf("Ceza yediniz! Kemer takmamak!");
    }
    if((hiz>lim) && kemer==1){
        printf("Limit hiz: %d, Hiziniz: %d, ceza yediniz",lim,hiz);
    }
    else if(kemer==1){
        printf("Seni sansli araba..");
    }
    return 0;
}

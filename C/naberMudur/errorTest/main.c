#include <stdio.h>
#include <stdlib.h>

void main()
{
    float benzin=0,km=0,toplambenzin=0,toplamkm=0,islem=0;
    while(1){
        printf("Gidilen yolu girin: ");
        scanf("%f",&km);
        printf("Harcanan benzini girin(Cikis icin -1): ");
        scanf("%f",&benzin);
        if (benzin==-1) break;
        islem=km/benzin;
        printf("ortalama: %f\n\n",islem);
        toplambenzin+=benzin;
        toplamkm+=km;
    }
    islem = toplamkm/toplambenzin;
    printf("toplam ortalama km/benzin: %f",islem);
}







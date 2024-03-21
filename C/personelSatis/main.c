#include <stdio.h>
#include <stdlib.h>

int PersonelAl(int);


int main()
{
    int personel=0,enYuksek=0;
    personel=PersonelAl(personel);
    int satisMiktar[personel];

    for(int i=0,gecici=0;i<personel;i++)
    {
        printf("\n\nLutfen %d.personel icin satis miktari giriniz: ",i+1);
        scanf("%d", &gecici);
        satisMiktar[i]=gecici;
        if(satisMiktar[i]>enYuksek)
        {
            enYuksek=satisMiktar[i];
        }
    }

    printf("En yuksek satis miktari: %d\n\n",enYuksek);

    for(int i=0;i<personel;i++)
    {
        printf("%d.personelin en yuksek satisa ulasmasi icin gereken satis miktari: %d\n",i+1,enYuksek-satisMiktar[i]);
    }

    return 0;
}


int PersonelAl(int p)
{
    while(p<=0 || p>50)
    {
        printf("Lutfen en fazla 50 olmak uzere personel sayisini giriniz: ");
        scanf("%d",&p);
    }

    return p;
}

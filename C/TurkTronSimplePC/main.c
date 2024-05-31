/*ORNEK PROGRAM:
1030 #30.hafiza bolgesine klavyeden giris al.
1031 #31.hafiza bolgesine klavyeden giris al.
2030 #30.hafiza bolgesindeki degeri akumulatore yukle
3031 #31.hafiza bolgesindeki deger ile akumulatordeki degeri topla ve akumulatore yukle.
2132 #Akumulatordeki degeri 32.hafiza bolgesine yukle.
1132 #32.hafiza bolgesindeki degeri ekrana yazdir.
4300 #Programdan cik.
-9999 #yazim asamasini sonlandir.
*/

#include <stdio.h>
#include <stdlib.h>

#define OKU 10 //hafizaya elle input gir
#define YAZ 11 //hafizadaki degeri yazdir

#define YUKLE 20 //akumulatore hafiza degerini yukle
#define SAKLA 21 //hafizaya akumulatorden deger yukle

#define TOPLA 30 //akumulatorle girilen hafiza bolmesindeki degeri topla
#define CIKART 31 //akumulatorle girilen hafiza bolmesindeki degeri cikart
#define BOL 32  //akumulatorle girilen hafiza bolmesindeki degeri carp
#define CARP 33 //akumulatorle girilen hafiza bolmesindeki degeri BOL
#define ARTIBIR 34 //akumulatoru 1 arttir

#define DALLAN 40 //PC yi belirtilen adrese ayarla
#define EKSIDALLAN 41 //AC degeri negatif ise PC yi belirtilen adrese ayarla
#define SIFIRDALLAN 42 //AC degeri 0 ise PC yi belirtilen adrese ayarla
#define BITIR 43 //programi sonlandir


int IS = 0;
int AK = 0;

int main()
{
    void ProgramGir(int []);
    void ProgramCalistir(int []);

    int hafiza[100]={0};
    ProgramGir(hafiza);
    ProgramCalistir(hafiza);
    return 0;
}

void ProgramGir(int hafiza[])
{
    int sayici=-1;
    printf("***BILGISAYAR -2'YE HOSGELDINIZ***\n***PROGRAM GIRMEK ICIN KODUN***\n***GIRISINDEKI YONERGEDEN FAYDALANABILIRSINIZ***\n***CIKIS ICIN -9999 GIRISI YAPINIZ***\n\n\n");

    while(hafiza[sayici]!=-9999)
    {
        sayici++;
        printf("%02d ? ",sayici);
        scanf("%d",&hafiza[sayici]);
        fflush(stdin);
    }

}

void ProgramCalistir(int hafiza[])
{
    void Oku(int *);
    void Yaz(int *);
    void Yukle(int *);
    void Sakla(int *);
    void Topla(int *);
    void Cikar(int *);
    void Carp(int *);
    void Bol(int *);
    void ToplaBir();
    void Dallan(int *);
    void EksiDallan(int *);
    void SifirDallan(int *);
    void KYaz(int *);

    int secim=0;
    int adres=0;

    while(secim!=43)
    {
        secim=hafiza[IS]/100;
        adres=hafiza[IS]%100;
        IS++;

        switch(secim){
            case 10:
                Oku(&hafiza[adres]);
                break;
            case 11:
                Yaz(&hafiza[adres]);
                break;
            case 20:
                Yukle(&hafiza[adres]);
                break;
            case 21:
                Sakla(&hafiza[adres]);
                break;
            case 30:
                Topla(&hafiza[adres]);
                break;
            case 31:
                Cikar(&hafiza[adres]);
                break;
            case 32:
                Carp(&hafiza[adres]);
                break;
            case 33:
                Bol(&hafiza[adres]);
                break;
            case 34:
                ToplaBir();
                break;
            case 40:
                Dallan(&adres);
                break;
            case 41:
                EksiDallan(&adres);
                break;
            case 42:
                SifirDallan(&adres);
                break;
        }
    }
}

void Oku(int *hafiza)
{
    scanf("%d",hafiza);
    fflush(stdin);
}

void Yaz(int *hafiza)
{
    printf("%d\n",*hafiza);
}

void Yukle(int *hafiza)
{
    AK=*hafiza;
}

void Sakla(int *hafiza)
{
    *hafiza=AK;
}

void Topla(int *hafiza)
{
    AK+=*hafiza;
}

void Cikar(int *hafiza)
{
    AK-=*hafiza;
}

void Carp(int *hafiza)
{
    AK*=*hafiza;
}

void Bol(int *hafiza)
{
    AK/=*hafiza;
}

void ToplaBir()
{
    AK++;
}

void Dallan(int *adres)
{
    AK=*adres;
}

void EksiDallan(int *adres)
{
    if(AK<0) IS=*adres;
}

void SifirDallan(int *adres)
{
    if(AK==0) IS=*adres;
}

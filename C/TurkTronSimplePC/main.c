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

#define OKU 10
#define YAZ 11

#define YUKLE 20
#define SAKLA 21

#define TOPLA 30
#define CIKART 31
#define BOL 32
#define CARP 33
#define ARTIBIR 34

#define DALLAN 40
#define EKSIDALLAN 41
#define SIFIRDALLAN 42
#define BITIR 43

void ProgramGir(int []);
void ProgramCalistir(int [],int *);

int main()
{
    int hafiza[100]={0};
    int akumulator=0;
    int *ACptr=&akumulator;
    ProgramGir(hafiza);
    ProgramCalistir(hafiza,ACptr);
    return 0;
}

void ProgramGir(int hafiza[])
{
    int sayici=-1;
    printf("***DANDIKSAYAR'A HOSGELDINIZ***\n***PROGRAM GIRMEK ICIN KODUN***\n***GIRISINDEKI YONERGEDEN FAYDALANABILIRSINIZ***\n***CIKIS ICIN -9999 GIRISI YAPINIZ***\n\n\n");

    while(hafiza[sayici]!=-9999)
    {
        sayici++;
        printf("%02d ? ",sayici);
        scanf("%5d",&hafiza[sayici]);
        fflush(stdin);
    }

}

void ProgramCalistir(int hafiza[],int *AC)
{
    void Oku(int *);
    void Yaz(int *);
    void Yukle(int *,int *);
    void Sakla(int *,int *);
    void Topla(int *,int *);
    void Cikar(int *,int *);
    void Carp(int *,int *);
    void Bol(int *,int *);
    void ToplaBir(int*);
    void Dallan(int *,int *);
    void EksiDallan(int *,int *,int *);
    void SifirDallan(int *, int *,int *);

    int PC=0;
    int secim=0;
    int adres=0;
    while(secim!=43)
    {
        secim=hafiza[PC]/100;
        adres=hafiza[PC]%100;
        PC++;
        switch(secim){
            case 10:
                Oku(&hafiza[adres]);
                break;
            case 11:
                Yaz(&hafiza[adres]);
                break;
            case 20:
                Yukle(&hafiza[adres],AC);
                break;
            case 21:
                Sakla(&hafiza[adres],AC);
                break;
            case 30:
                Topla(&hafiza[adres],AC);
                break;
            case 31:
                Cikar(&hafiza[adres],AC);
                break;
            case 32:
                Carp(&hafiza[adres],AC);
                break;
            case 33:
                Bol(&hafiza[adres],AC);
                break;
            case 34:
                ToplaBir(AC);
                break;
            case 40:
                Dallan(&PC,&adres);
                break;
            case 41:
                EksiDallan(&PC,&adres,AC);
                break;
            case 42:
                SifirDallan(&PC,&adres,AC);
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

void Yukle(int *hafiza,int *AC)
{
    *AC=*hafiza;
}

void Sakla(int *hafiza,int *AC)
{
    *hafiza=*AC;
}

void Topla(int *hafiza,int *AC)
{
    *AC+=*hafiza;
}

void Cikar(int *hafiza,int *AC)
{
    *AC-=*hafiza;
}

void Carp(int *hafiza,int *AC)
{
    *AC*=*hafiza;
}

void Bol(int *hafiza,int *AC)
{
    *AC/=*hafiza;
}

void ToplaBir(int *AC)
{
    (*AC)++;
}

void Dallan(int *PC,int *adres)
{
    *PC=*adres;
}

void EksiDallan(int *PC,int *adres,int *AC)
{
    if(*AC<0)*PC=*adres;
}

void SifirDallan(int *PC,int *adres,int *AC)
{
    if(*AC==0)*PC=*adres;
}

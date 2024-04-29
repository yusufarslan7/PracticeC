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
#define KYAZ 12 //belirtilen bolmeden baslayarak 0'a ulasana dek hafiza bolmesindeki degerin ASCII karsiligini ekrana yazdir.

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

void ProgramGir(int []);
void ProgramCalistir(int []);

register int PC=0;
register int AC=0;

int main()
{
    int hafiza[100]={0};
    ProgramGir(hafiza);
    ProgramCalistir(hafiza);
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

void ProgramCalistir(int hafiza[])
{
    void OkuYadaYaz(int *,short);
    void KYAZ(int *);
    void YukleVeyaSakla(int *,int *);
    void DortIslem(int *,int *,short);
    void ToplaBir(int*);
    void Dallanizm(int *,int *,int *,short);

    int secim=0;
    int adres=0;
    while(secim!=43)
    {
        secim=hafiza[PC]/100;
        adres=hafiza[PC]%100;
        PC++;
        switch(secim){
            case 10:
                OkuYadaYaz(&hafiza[adres],1);
                break;
            case 11:
                OkuYadaYaz(&hafiza[adres],2);
                break;
            case 12:
                KYaz(&hafiza[adres]);
                break;
            case 20:
                YukleVeyaSakla(&hafiza[adres],AC);
                break;
            case 21:
                YukleVeyaSakla(AC,&hafiza[adres]);
                break;
            case 30:
                DortIslem(&hafiza[adres],AC,1);
                break;
            case 31:
                DortIslem(&hafiza[adres],AC,2);
                break;
            case 32:
                DortIslem(&hafiza[adres],AC,3);
                break;
            case 33:
                DortIslem(&hafiza[adres],AC,4);
                break;
            case 34:
                ToplaBir(AC);
                break;
            case 40:
                Dallanizm(&PC,&adres,AC,1);
                break;
            case 41:
                Dallanizm(&PC,&adres,AC,2);
                break;
            case 42:
                Dallanizm(&PC,&adres,AC,3);
        }
    }
}

void OkuYadaYaz(int *hafiza,short tip)
{
    switch(tip)
    {
    case 1:
        scanf("%d",hafiza);
        fflush(stdin);
        break;
    case 2:
        printf("%d\n",*hafiza);
        break;
    }
}

void KYaz(int *hafiza)
{
    for(int i=0;*(hafiza+i)!=0;i++)
    {
        printf("%c",*(hafiza+i));
    }
    printf("\n");
}

void YukleVeyaSakla(int *A,int *B)
{
    *B=*A;
}

void DortIslem(int *hafiza,int *AC,short tip)
{
    switch(tip)
    {
    case 1: //topla
        *AC+=*hafiza;
        break;
    case 2: //cikar
        *AC-=*hafiza;
        break;
    case 3: //carp
        *AC*=*hafiza;
        break;
    case 4: //bol
        *AC/=*hafiza;
        break;
    }
}

void Dallanizm(int *PC,int *adres,int *AC,short tip)
{
    if(tip==1)*PC=*adres; //Dallan
    else if(*AC<0 && tip==2)*PC=*adres; //EksiDallan
    else if(*AC==0 && tip==3)*PC=*adres; //SifirDallan
}

void ToplaBir(int *AC)
{
    (*AC)++;
}

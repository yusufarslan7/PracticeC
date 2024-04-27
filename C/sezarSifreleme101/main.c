#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void desifre(char *,const char *,const char *);

int main()
{
    char alfabe[70]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUWXVYZ0123456789 .!:()";
    char bizimki[256]={""};
    char sifre[256]={""};

    printf("sifreli metin gir: ");
    fgets(bizimki,256,stdin);
    fflush(stdin);

    printf("sifreyi gir: ");
    fgets(sifre,256,stdin);

    desifre(bizimki,sifre,alfabe);

    printf("Desifre edilmis metin: ");

    puts(bizimki);

    return 0;
}

void desifre(char *sifreliString,const char *sifre,const char *alfabe)
{
    int temp = 0;
    int a=strlen(sifre)-1;

    for(int i=0;i<strlen(sifreliString)-1;i++)
    {
        temp = (strchr(alfabe,*(sifreliString+i))-alfabe) - (strchr(alfabe,*(sifre + (i % a)))-alfabe);
        if(temp < 0) temp += 69;
        if(temp >68) temp -=69;

        *(sifreliString+i)= *(alfabe + temp);
    }

}

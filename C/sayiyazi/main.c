#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sayi[15];
    int a=0;
    printf("Sayi gir: ");
    scanf("%s", &sayi);
    int b=strlen(sayi);

    for(int i=0;i<strlen(sayi);i++)
    {

    if (b%3==0)
        switch(sayi[i])
        {
            case '1':
                printf("yuz ");
                break;
            case '2':
                printf("iki yuz ");
                break;
            case '3':
                printf("uc yuz ");
                break;
            case '4':
                printf("dort yuz ");
                break;
            case '5':
                printf("bes yuz ");
                break;
            case '6':
                printf("alti yuz ");
                break;
            case '7':
                printf("yedi yuz ");
                break;
            case '8':
                printf("sekiz yuz ");
                break;
            case '9':
                printf("dokuz yuz ");
                break;
        }
        if (b%3==2)
        switch(sayi[i])
        {
            case '1':
                printf("on ");
                break;
            case '2':
                printf("yirmi ");
                break;
            case '3':
                printf("otuz ");
                break;
            case '4':
                printf("kirk ");
                break;
            case '5':
                printf("elli ");
                break;
            case '6':
                printf("altmis ");
                break;
            case '7':
                printf("yetmis ");
                break;
            case '8':
                printf("seksen ");
                break;
            case '9':
                printf("doksan ");
                break;
        }
        if(b%3==1)
        switch(sayi[i])
        {
            case '1':
                printf("bir ");
                break;
            case '2':
                printf("iki ");
                break;
            case '3':
                printf("uc ");
                break;
            case '4':
                printf("dort ");
                break;
            case '5':
                printf("bes ");
                break;
            case '6':
                printf("alti ");
                break;
            case '7':
                printf("yedi ");
                break;
            case '8':
                printf("sekiz ");
                break;
            case '9':
                printf("dokuz ");
                break;
        }
        b--;
        if(b%3==0)
        {
            if(b>=12) printf("trilyon ");
            else if(b>=9) printf("milyar ");
            else if(b>=6) printf("milyon ");
            else if(b>=3) printf("bin ");
        }
    }
    return 0;
}

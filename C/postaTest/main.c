#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fonk(char []);

int main()
{
    printf("POSTA GIR: ");
    char* posta[1][256];
    scanf("%256s",posta[0]);

    int sonuc = fonk(posta[0]);

    if(sonuc == 1)
    {
        printf("uygun");
    }
    else
    {
        printf("uygun degil");
    }
    return 0;
}

int fonk(char a[])
{
    char b[3][256]={""};

    int val = sscanf(a,"%[^@]@%[^.].%s",b[0],b[1],b[2]);
    printf("\n%s %s %s\n\n",b[0],b[1],b[2]);
    if(val !=3)return 0;
    if(b[0][0]=='@' || b[0][0]=='.')return 0; //. @ baslama test
    if((b[2][strlen(b[2])-1]=='@') || (b[2][strlen(b[2])-1]=='.'))return 0; // .@ bitme test
    if(strchr(b[1],'@') || strchr(b[2],'@')) return 0; // 1 tane @ olma test
    if(b[0][strlen(b[0])-1]=='.')return 0; // .@ test
    if(strstr(b[0],"..")||strstr(b[2],".."))return 0; //ardisik nokta testi
    if(b[2][0]=='.')return 0;//ardisik nokta testi b2

    return 1;
}

#include<stdio.h>

int main(){
    /*for (int i = 0; i < 4; i++)
    {
        printf("*  *  *  *  *  *  *  *\n *  *  *  *  *  *  *  *\n");
    }
    return 0;*/
    /*int numberX;
    printf("5 basamakli tamsayi gir: ");
    scanf("%d",&numberX);
    printf("%d\t%d\t%d\t%d\t%d",numberX/10000,numberX/1000%10,numberX/100%10,(numberX/10)%10,numberX%10);
    return 0;*/
    /*int score;
    printf("Notunuzu giriniz: ");
    scanf("%d",&score);
    if(score >= 60) {
        printf("Gectin");
    }
    else {
        printf("HAHAHAHA MALA BAK AHAHAHAHAHA");
    }
    return 0;*/
    /*int not;
    printf("Not: ");
    scanf("%d", &not);
    printf("%s\n", not == 31 ?"Komik Not" : "Komik olmayan not...");*/
    float not;
    printf("Not: ");
    scanf("%f", &not);
    not != 31 ? printf("Begenmedim tekrar gir.\n\n") : printf("Aferin.\n");
    if (not != 31){
        main();
    }
    return 0;
}
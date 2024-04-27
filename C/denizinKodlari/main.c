#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

char melee_weapons[300] = {"! Sopa ! Bicak ! Kalkan ! Kilic ! Mizrak ! Gurz ! Savas Baltasi ! Savas Cekici ! Baltali Kargi ! Katana ! Buyuk Kilic ! Ekskalibur !"};
char ranged_weapons[300] = {"! Sapan ! Firlatma Bicaklari ! Yay ! Cirit ! Kundakli Yay ! Altipatlar ! Tufek ! Roket Atar ! Mitralyoz !"};
char magic_weapons[300] = {"! Asa ! Supurge ! Kitap! Buyu Flutu! Buyuk Asa ! Buyu Karti ! Buyulu Kure ! Arkanum !"};
char prefixes[300] = {"! Bakir ! Demir ! Celik ! Obsidyen ! Kristal ! Hiz ! Olum karisimli ! Teknolojik ! Yikim ! Hiper Olum ! Sonsuzluk ! Izgara Peynir !"};
char elements[300] = {"! Atevli! Su Elementi! Hava Fiskirtan! Zehirli! Elektrikli! Buz Yayan! Kara Element! Toprak Bozan! Kutsal Element! Patlama Destekli!"};
char postfixes[300] = {"!Ufak!Buyuk!Keskin!Tehlikeli!Guclu!Kanli!Dovulmus!Yukseltilmis!Sihirli!Nadir!Kutsal!Sibernetik!Gercekdisi!Mistik!Efsanevi!"};
char postfix[40] = {0};
char element[40] = {0};
char main_part[20] = {0};
char prefix[20] = {0};
short main_class = 0;

// 12 melee
// 9 ranged
// 8 magic
// 15 prefix
// 10 element
// 12 postfix

void SummonTheListPickingFunctionsAccordingToTheParameters(short, float);
void RandomizeWeapon(char* ,char* ,float, short);
short RandButLiterallyBetter(short, float);

int main()
{
    short choice=0;
    memset(main_part,0,20);
    srand(time(NULL)); // shitty chest = 2 luck,    standard = 1.5 luck    good chest = 1.25 luck    legendary chest = 1 luck
    start:
    printf("What would you like to do? \n1-)Open Shitty Chest.\n2-)Open Standard Chest.\n3-)Open Good Chest.\n4-)Open Legendary Chest.\n");
    scanf("%hd", &choice);
    switch(choice)
    {
    case 1:
            memset(main_part,0,20);
            memset(prefix,0,20);
            memset(element,0,40);
            memset(postfix,0,40);
            SummonTheListPickingFunctionsAccordingToTheParameters(1,2);
            printf("\nYou got%s%s%s%s!\n\n",element,prefix,postfix,main_part);
        break;
    case 2:
            memset(main_part,0,20);
            memset(prefix,0,20);
            memset(element,0,40);
            memset(postfix,0,40);
            SummonTheListPickingFunctionsAccordingToTheParameters(1,1.5);
            printf("\nYou got%s%s%s%s!\n\n",element,prefix,postfix,main_part);
        break;
    case 3:
            memset(main_part,0,20);
            memset(prefix,0,20);
            memset(element,0,40);
            memset(postfix,0,40);
            SummonTheListPickingFunctionsAccordingToTheParameters(1,1.25);
            printf("\nYou got%s%s%s%s!\n\n",element,prefix,postfix,main_part);
        break;
    case 4:
            memset(main_part,0,20);
            memset(prefix,0,20);
            memset(element,0,40);
            memset(postfix,0,40);
            SummonTheListPickingFunctionsAccordingToTheParameters(1,1);
            printf("\nYou got%s%s%s%s!\n\n",element,prefix,postfix,main_part);
        break;
    default:
        break;
    }
    goto start;
    return 0;
}

void RandomizeWeapon(char* names, char* picked_name, float luck, short randomtype)
{
    short count=0, picked=0;
    int i=0, j=0;
    for(i=0; *(names+i)!='\0' ;i++) //check to see how many '!' are present
    {
        if(*(names+i)=='!')
            count++;
    }
    count--; //weapon count is 1 lower than '!' count
    if(randomtype==1)picked = RandButLiterallyBetter(count, luck);
    else picked = (rand()%count)+1;
    for(i=0, count=0; picked!=count ;i++) //go to the '!' of the randomly picked weapon
    {
        if(*(names+i)=='!')
            count++;
    }
    for(j=0; *(names+i)!='!' ;i++,j++) //print weapon name until hits '!' into the main_part
    {
        picked_name[j] = *(names+i); //gets pretty funny if u replace picked_name with main_part
    }
}

short RandButLiterallyBetter(short possibilities, float luck)
{
    short i=possibilities;
    double randval=0;
    if(luck>1.25)
    {
        randval = (((rand()%100000)+1)/100000.0)+(0.95/pow(i,luck)); //0.00001
        for(i=possibilities; possibilities>0 ;i--)
        {
            if(randval<=(1/pow(i,luck)))
            {
                return i;
            }
        }
    }
    else
    {
        randval = (((rand()%100000)+1)/100000.0)+(1.37/pow(i,luck)); //0.00001
        for(i=possibilities; possibilities>0 ;i--)
        {
            if(randval<=((1/pow(i,luck))+(5/pow(i,luck+1))))
            {
                return i;
            }
        }
    }
    return 1;
}

void SummonTheListPickingFunctionsAccordingToTheParameters(short mode, float luck)
{ // mode is leftover variable and has no useful function, Im too lazy to remove it
    if(mode==1)
    {
        short r=rand()%3;
        switch(r)
        {
        case 0:
            main_class = 1;
            RandomizeWeapon(melee_weapons, main_part, luck, 1);
            break;
        case 1:
            main_class = 2;
            RandomizeWeapon(ranged_weapons, main_part, luck, 1);
            break;
        case 2:
            main_class = 3;
            RandomizeWeapon(magic_weapons, main_part, luck, 1);
            break;
        default:
            break;
        }
        if((rand()%100)+1 > pow(luck,3)*10) RandomizeWeapon(prefixes, prefix, luck, 1);
        if((rand()%100)+1 > pow(luck,3)*12) RandomizeWeapon(elements, element, luck, 2);
        if((rand()%100)+1 > pow(luck,3)*10) RandomizeWeapon(postfixes, postfix, luck, 1);
    }
}

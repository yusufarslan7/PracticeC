#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char melee_weapons[300] = {"! Club ! Dagger ! Sickle ! Shield ! Sword ! Spear ! Mace ! Battle Axe ! War Hammer ! Halberd ! Katana ! Greatsword ! Excalibur !"};
char ranged_weapons[300] = {"! Slingshot ! Throwing knives ! Shurikens ! Bow ! Javelins ! Crossbow ! Revolver ! Rifle ! Rocket Launcher ! Minigun !"};
char magic_weapons[300] = {"! Wand ! Broom ! Book ! Magic Flute ! Staff ! Spellcard ! Magic Orb ! Scroll ! Arcanum !"};
char prefixes[300] = {"! Small! Large! Sharp! Dangerous! Strong! Bloodied! Forged! Enchanted! Magical! Rare! Sacred! Cybernetic! Unreal! Mythical! Legendary!"};
char elements[300] = {"! Fiery! Water Elemental! Air Blowing! Poisonous! Thunderous! Ice Conjuring! Dark Elemental! Earth Manipulating! Holy Elemental! Explosion Powered!"};
char postfixes[300] = {"!of Copper !of Iron !of Steel !of Obsidian !of Gold !of Crystal !of Speed !of Death !of Technology !of Homa !of Destruction !of HyperDeath !of Infinity !of Grilled Cheese !"};
char postfix[40] = {0};
char element[40] = {0};
char main_part[20] = {0};
char prefix[20] = {0};
short main_class = 0;
short activeslot = 0;
short timesincelastmimic = 0;
int rarity = 0;
long gold = 25;


// weapon index for inventory and index itself  (v, x, y, z, c, b)
// v = class of the weapon
// x = element
// y = prefix
// z = weapon itself
// c = postfix
// b = rarity
int inventory[10][6] = {0};
int weapon_index[6] = {0};

// 13 melee
// 10 ranged
// 9 magic
// 15 prefix
// 10 element
// 14 postfix
void SummonTheListPickingFunctionsAccordingToTheParameters(short, float);
void RandomizeWeapon(char* ,char* ,float, short);
short RandButLiterallyBetter(short, float);
short DisplayRarity(void);
short CountItems(char*);
short RollingPhase(short);
void formalite(void);
void OpenInventory(short);
void PrintName(char*,short);
short InsertInventory(void);
void SaveProgress(short slot);
void LoadProgress(short slot);
short SelectASave(void);
void CheckTheSaveContents(FILE* SaveFile);
void DeleteASave(void);
short MimicCheck(short chesttype);

int main()
{
    short choice=0;
    memset(main_part,0,20);
    srand(time(NULL)); // shitty chest = 1.88 luck,    standard = 1.4 luck    good chest = 1.25 luck    legendary chest = 1 luck
    activeslot = SelectASave();
    LoadProgress(activeslot);
    start:
    system("cls");
    SaveProgress(activeslot);
    printf("\n******** \x1b[33mYou have %ld gold\x1b[0m *********\nWhat would you like to do? \n1-)Beg for money.\n2-)Open Shitty Chest.(5 gold)\n3-)Open Standard Chest.(25 gold)\n4-)Open Good Chest.(80 gold)\n5-)Open Legendary Chest.(150 gold)\n6-)Open inventory\n7-)Switch to a different Save File\n8-)Delete a Save File\n***********************************\n",gold);
    scanf("%hd", &choice);
    fflush(stdin);
    memset(weapon_index,0,5*sizeof(short));
    memset(main_part,0,20);
    memset(prefix,0,20);
    memset(element,0,40);
    memset(postfix,0,40);
    if(RollingPhase(choice)==0) goto start; // rolls, tells the weapon name, value, asks for which action to take
    scanf("%hd",&choice);
    switch(choice)
    {
    case 1:
        if(InsertInventory()==0) goto start;
        break;
    case 2:
        gold += rarity/40;
        printf("Sold for %d gold!", rarity/40);
        break;
    case 3:
        if(rarity/40 < 1) printf("You throw the weapon at the ground, looking at it one final time in disappointment.\n");
        else if(rarity/40 < 15) printf("You throw the weapon at the ground, it looked like it would sell for some gold but you decided to deny it the satisfaction of being held by someone else.\n");
        else if(rarity/40 < 75) printf("For some reason, you decide that this quite fine weapon sucks, I guess you don't need the money or it's use after all.\n");
        else if(rarity/40 < 200) printf("You throw this masterpiece on the ground, it shines from behind you as you walk away.\n");
        else if(rarity/40 < 500) printf("You drop the legendary weapon worth a fortune, it causes massive damage to the ground even though you were gentle with it.\n");
        else printf("The weapon understands your intentions and promptly teleports away, it is not in the mood nor at the level to be thrown to the ground.");
        break;
    }
    goto start;
    return 0;
}

short InsertInventory(void)
{
    short selection=0;
    for(int inven=0; inven<10 ;inven++)
    {
        if(inventory[inven][3]==0)
        {
            for(int i=0; i<6 ;i++)
            {
                inventory[inven][i] = weapon_index[i];
            }
            return 1;
        }
    }
    OpenInventory(0);
    printf("\n\x1b[31mInventory full!\x1b[37m\nWould you like to replace one of the slots?\n0-)No\n1-10-)Replace the weapon in the inputted slot.\n");
    scanf("%hd",&selection);
    if(selection<=10 && selection>=1)
        for(int i=0; i<6 ;i++)
        {
            inventory[selection][i] = weapon_index[i];
            return 1;
        }
    return 0;
}

void OpenInventory(short type)
{
    inventory:;
    short insel = 0, inv = 0, insel2=0;
    int temp[6] = {0};
    printf("\n\n\x1b[34m/////////////////////////Inventory//////////////////////////////\x1b[0m");
    for(inv=0; inv<10 ;inv++)
    {
        printf("\n\x1b[34m//\x1b[0m  %2d-)",inv+1);
        if(inventory[inv][3]==0) printf(" ------------------EMPTY--------------------");
        else
        {
            PrintName(elements,inventory[inv][1]);
            PrintName(prefixes,inventory[inv][2]);
            if(inventory[inv][0]==1) PrintName(melee_weapons,inventory[inv][3]);
            if(inventory[inv][0]==2) PrintName(ranged_weapons,inventory[inv][3]);
            if(inventory[inv][0]==3) PrintName(magic_weapons,inventory[inv][3]);
            PrintName(postfixes,inventory[inv][4]);
            printf("(level %d weapon)",inventory[inv][5]);
        }
    }
    printf("\n\x1b[34m////////////////////////////////////////////////////////////////\x1b[0m\n\n");
    if(type==1)
    {
        printf("############ Inventory Manager ############\n");
        printf("1-)Sell a weapon.\n2-)Discard a weapon\n3-)Move a weapon to another slot\n4-)Try a Weapon\n0-)Close Inventory\n");
        printf("###########################################\n\n");
        scanf("%hd",&insel);
        switch(insel)
        {
        case 1:
            printf("Input the slot of the weapon you would like to sell: ");
            scanf("%hd",&insel);
            if(insel<1 || insel>10) goto inventory;
            gold += inventory[insel-1][5]/12;
            printf("Sold for %d gold\n",inventory[insel-1][5]/12);
            for(inv=0; inv<6 ;inv++) inventory[insel-1][inv] = 0;
            goto inventory;
            break;
        case 2:
            printf("Input the slot of the weapon you would like to trash: ");
            scanf("%hd",&insel);
            if(insel<1 || insel>10) goto inventory;
            for(inv=0; inv<6 ;inv++) inventory[insel-1][inv] = 0;
            goto inventory;
            break;
        case 3:
            printf("Enter two slot numbers, first input will be moved to the second input: ");
            scanf("%hd",&insel);
            scanf("%hd",&insel2);
            if(insel<1 || insel>10) goto inventory;
            for(inv=0; inv<6 ;inv++) temp[inv] = inventory[insel-1][inv];
            for(inv=0; inv<6 ;inv++) inventory[insel-1][inv] = inventory[insel2-1][inv];
            for(inv=0; inv<6 ;inv++) inventory[insel2-1][inv] = temp[inv];
            printf("Swapped slots %hd and %hd",insel,insel2);
            goto inventory;
            break;
        case 4:
            printf("Input the slot of the weapon you would like to Try: ");
            scanf("%hd",&insel);
            fflush(stdin);
            if(insel<1 || insel>10) goto inventory;
            for(inv=0; inv<6 ;inv++) inventory[insel-1][inv] = 0;
            goto inventory;
            break;

        default:

            break;
        }
    }
}

short RollingPhase(short type)
{
    switch(type)
    {
    case 1:
        {
            printf("\n\n\x1b[32mYou successfully beg for 2 gold!\x1b[0m\n\n");
            gold += 2;
            return 0;
        }
        break;
    case 2:
        if(gold >= 5)
        {
            gold -= 5;
            SummonTheListPickingFunctionsAccordingToTheParameters(1,2.0);
            formalite();
        }
        else
        {
            printf("\n\x1b[31mNot enough gold for this chest.\x1b[0m\n");
            return 0;
        }
        break;
    case 3:
        if(gold >= 25)
        {
            gold -= 25;
            SummonTheListPickingFunctionsAccordingToTheParameters(1,1.40);
            formalite();
        }
        else
        {
            printf("\n\x1b[31mNot enough gold for this chest.\x1b[0m\n");
            return 0;
        }
        break;
    case 4:
        if(gold >= 75)
        {
            gold -= 75;
            if(1 == MimicCheck(3))
                return 0;
            timesincelastmimic++;
            SummonTheListPickingFunctionsAccordingToTheParameters(1,1);
            formalite();
        }
        else
        {
            printf("\n\x1b[31mNot enough gold for this chest.\x1b[0m\n");
            return 0;
        }
        break;
    case 5:
        if(gold >= 125)
        {
            gold -= 125;
            if(1 == MimicCheck(4))
                return 0;
            timesincelastmimic++;
            SummonTheListPickingFunctionsAccordingToTheParameters(1,0.5);
            formalite();
        }
        else
        {
            printf("\n\x1b[31mNot enough gold for this chest.\x1b[0m\n");
            return 0;
        }
        break;
    case 6:
        OpenInventory(1);
        return 0; //replace with inventory management options, for now it just skips to the main menu
        //oops we didnt replace it with inventory management, I guess this is now used to escape to main menu regardless
        break;
    case 7:
        activeslot = SelectASave();
        return 0;
        break;
    case 8:
        DeleteASave();
        return 0;
        break;
    case 9:;
        // legendary chest 210
        // good chest 129(1 luck) 93(1.25 luck)
        // standard 41(1.4 luck)
        // shitty 10
        int f=0;
        for(int g=0; g<10000 ;g++){
        SummonTheListPickingFunctionsAccordingToTheParameters(1,1.40);
        printf("\nYou got%s%s%s%s!\n",element,prefix,main_part,postfix);
        DisplayRarity();
        memset(weapon_index,0,5*sizeof(short));
        memset(main_part,0,20);
        memset(prefix,0,20);
        memset(element,0,40);
        memset(postfix,0,40);
        //if(rarity>17142-2857) f++;
        gold += rarity/40;}
        printf("%d",f);
        return 0;
        break;
    default:
        return 0;
    }
    return 1;
}

void formalite(void)
{
    printf("\nYou got");
    switch(DisplayRarity())
    {
    case 1:
        printf("\033[2m");break;
    case 2:
        printf("\033[0m");break;
    case 3:
        printf("\033[36m");break;
    case 4:
        printf("\033[35m\033[1m");break;
    case 5:
        printf("\033[33m\033[1m\033[4m");break;
    case 6:
        printf("\033[31m\033[43m\033[4m");break;
    case 7:
        printf("\033[1m\033[3m\033[45m\033[36m\033[4m");break;
    }
    printf("\x1b[F\x1b[8G");
    printf("%s%s%s%s\033[0m!\n\n\n\n",element,prefix,main_part,postfix);
    printf("\x1b[36m------------------------------------------------\n");
    printf("What would you like to do with the weapon:\x1b[0m\n");
    printf("1-)Keep it\n");
    printf("2-)Sell it(%d gold)\n",rarity/40);
    printf("3-)Discard it\n");
    printf("\x1b[36m------------------------------------------------\x1b[0m\n\n");
}

void PrintName(char* names, short index)
{
    int i=0, count=0;
    for(i=0, count=0; index!=count ;i++) //go to the '!' of the randomly picked weapon
    {
        if(*(names+i)=='!')
            count++;
    }
    for(; *(names+i)!='!' ;i++) //print weapon name until hits '!'
    {
        printf("%c",*(names+i));
    }
}

void RandomizeWeapon(char* names, char* picked_name, float luck, short whichcomponent)
{
    // Despite the name, it is used to randomize words, called several times just to write the name of a single weapon
    short count=0, picked=0;
    int i=0, j=0;
    for(i=0; *(names+i)!='\0' ;i++) //check to see how many '!' are present
    {
        if(*(names+i)=='!')
            count++;
    }
    count--; //weapon count is 1 lower than '!' count
    if(whichcomponent==1)
    {
        picked = (rand()%count)+1;
    }
    else
    {
        picked = RandButLiterallyBetter(count, luck);
    }
    weapon_index[whichcomponent] = picked;
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
{
    rarity=1;
    short r=rand()%3;
    switch(r)
    {
    case 0:
        main_class = 1;
        weapon_index[0] = 1;
        RandomizeWeapon(melee_weapons, main_part, luck, 3);
        break;
    case 1:
        main_class = 2;
        weapon_index[0] = 2;
        RandomizeWeapon(ranged_weapons, main_part, luck, 3);
        break;
    case 2:
        main_class = 3;
        weapon_index[0] = 3;
        RandomizeWeapon(magic_weapons, main_part, luck, 3);
        break;
    default:
        break;
    }
    if((rand()%100)+1 > pow(luck,3)*10) RandomizeWeapon(prefixes, prefix, luck, 2);
    if((rand()%100)+1 > pow(luck,3)*12) RandomizeWeapon(elements, element, luck, 1);
    if((rand()%100)+1 > pow(luck,3)*10) RandomizeWeapon(postfixes, postfix, luck, 4);
}

short DisplayRarity(void)
{
    int maxscore=0;
    //max level 20000ish
    //1.1  1.2  1.5
    //wep %10
    //pre+wep %25
    //pre+post+wep %50
    //pre+post+wep+elem %100
    switch(main_class)
    {
    case 1:
        rarity += weapon_index[3]*weapon_index[3]*(2000/(CountItems(melee_weapons)*CountItems(melee_weapons)));
        break;
    case 2:
        rarity += weapon_index[3]*weapon_index[3]*(2000/(CountItems(ranged_weapons)*CountItems(ranged_weapons)));
        break;
    case 3:
        rarity += weapon_index[3]*weapon_index[3]*(2000/(CountItems(magic_weapons)*CountItems(magic_weapons)));
        break;
    }
    // rarity is assigned here
    rarity += weapon_index[2]*weapon_index[2]*(2500/(CountItems(prefixes)*CountItems(prefixes)));
    if(weapon_index[2]>0) rarity *= 1.1;
    rarity += weapon_index[4]*weapon_index[4]*(3350/(CountItems(postfixes)*CountItems(postfixes)));
    if(weapon_index[4]>0) rarity *= 1.2;
    if(weapon_index[1]>0)rarity *= 2;
    maxscore += ((4500*1.1)+3350)*1.2*2;
    weapon_index[5] = rarity;
    printf("\nLevel %d Weapon, at %.2f percent of max potential,",rarity,(rarity*100.0/maxscore));
    //common, uncommon, rare, epic, legendary, prime, ascended
    if((rarity*100.0/maxscore)<100/7) printf("\033[2m common \033[0mdrop");
    else if((rarity*100.0/maxscore)<(100/7)*2) printf("\033[0m uncommon drop");
    else if((rarity*100.0/maxscore)<(100/7)*3) printf("\033[36m rare \033[0mdrop");
    else if((rarity*100.0/maxscore)<(100/7)*4) printf("\033[35m\033[1m epic \033[0mdrop");
    else if((rarity*100.0/maxscore)<(100/7)*5) printf("\033[33m\033[1m\033[4m legendary \033[0mdrop");
    else if((rarity*100.0/maxscore)<(100/7)*6) printf("\033[31m\033[43m\033[4m prime \033[0mdrop");
    else printf("\033[1m\033[3m\033[45m\033[36m\033[4m ascended \033[0mdrop");
    return ((rarity*100.0/maxscore)/(100/7))+1;
}

short CountItems(char* names)
{
    int i=0, count=0;
    for(i=0; *(names+i)!='\0' ;i++) //check to see how many '!' are present
    {
        if(*(names+i)=='!')
            count++;
    }
    return count-1;
}

short MimicCheck(short chesttype)
{
    long stolen = 0;
    chesttype-=2;
             //0 to inf         //3 or 6
    if( (3*timesincelastmimic)+(3*chesttype) > (rand()%100)+1 )
    {
        stolen = (gold*((rand()%60)+1))/100;
        printf("\n\n\n\n\x1b[31mIt's a mimic!\n\n");
        printf("Mimic Steals %ld gold from you!\x1b[0m\n\n\n", stolen);
        gold-=stolen;
        timesincelastmimic = 0;
        return 1;
    }
    return 0;
}

///////////////Functions about save files start here/////////////////////

void SaveProgress(short slot)
{
    char filename[40] = {};
    sprintf(filename,"SaveFile%hd.txt", slot);
    FILE* SaveFile;
    SaveFile = fopen(filename,"w");
    short inviterate = 0;
    if(SaveFile == NULL) printf("\nSomething went wrong while opening the file. Progress couldnt be saved.\n");
    fprintf(SaveFile,"$%ld\n",gold);
    for(inviterate=0; inviterate<10 ;inviterate++) fprintf(SaveFile,"!%d %d %d %d %d %d",inventory[inviterate][0],inventory[inviterate][1],inventory[inviterate][2],inventory[inviterate][3],inventory[inviterate][4],inventory[inviterate][5]);
    fclose(SaveFile);
}

void LoadProgress(short slot)
{
    char filename[40] = {};
    sprintf(filename,"SaveFile%hd.txt", slot);
    FILE* SaveFile;
    short j=0;
    SaveFile = fopen(filename,"r");
    if(SaveFile == NULL)
    {
        printf("\nThe file appears to be empty, hopefully it's just a new save and not an error.\n");
        SaveProgress(slot);
        return;
    }
    fscanf(SaveFile,"$%ld\n",&gold);
    for(j=0; j<10 ;j++) fscanf(SaveFile,"!%d %d %d %d %d %d\n",&inventory[j][0],&inventory[j][1],&inventory[j][2],&inventory[j][3],&inventory[j][4],&inventory[j][5]);
    fclose(SaveFile);
}

short SelectASave(void)
{
    short pickedslot = 0;
    FILE* SaveFile;
    printf("\n\nSelect a Save slot you would like to load.");
    SaveFile = fopen("SaveFile1.txt","r");
    printf("\nSlot 1: ");
    CheckTheSaveContents(SaveFile);
    fclose(SaveFile);
    SaveFile = fopen("SaveFile2.txt","r");
    printf("\nSlot 2: ");
    CheckTheSaveContents(SaveFile);
    fclose(SaveFile);
    SaveFile = fopen("SaveFile3.txt","r");
    printf("\nSlot 3: ");
    CheckTheSaveContents(SaveFile);
    fclose(SaveFile);
    printf("\n");
    scanf("%hd", &pickedslot);
    if(pickedslot > 3 || pickedslot < 1)
    {
        printf("Invalid value entered, defaulting to slot 1");
        pickedslot = 1;
    }
    LoadProgress(pickedslot);
    return pickedslot;
}

void CheckTheSaveContents(FILE* SaveFile)
{
    long goldval = 0;
    int indexes[6] = {0};
    short inventoryfullness = 0;
    if(SaveFile == NULL) printf("Empty Save Slot");
    else
    {
        fscanf(SaveFile,"$%ld\n",&goldval);
        for(short j=0; j<10 ;j++)
        {
            fscanf(SaveFile,"!%d %d %d %d %d %d\n", &indexes[0], &indexes[1], &indexes[2], &indexes[3], &indexes[4], &indexes[5]);
            if(indexes[3] != 0) inventoryfullness++;
            indexes[3] = 0;
        }
        printf("%ld gold, %hd items stored", goldval, inventoryfullness);
    }
}

void DeleteASave(void)
{
    short pickedslot = 0;
    char filename[40] = {0};
    FILE* SaveFile;
    printf("\n\n\x1b[31m!!!  Select a Save slot you would like to delete  !!!\x1b[0m");
    SaveFile = fopen("SaveFile1.txt","r");
    printf("\nSlot 1: ");
    CheckTheSaveContents(SaveFile);
    fclose(SaveFile);
    SaveFile = fopen("SaveFile2.txt","r");
    printf("\nSlot 2: ");
    CheckTheSaveContents(SaveFile);
    fclose(SaveFile);
    SaveFile = fopen("SaveFile3.txt","r");
    printf("\nSlot 3: ");
    CheckTheSaveContents(SaveFile);
    fclose(SaveFile);
    printf("\n4-)No no no I changed my mind!");
    printf("\n");
    scanf("%hd", &pickedslot);
    if(pickedslot > 4 || pickedslot < 1) printf("Invalid value entered, no deletion will be made :)");
    else
    {
        sprintf(filename,"SaveFile%d.txt",pickedslot);
        SaveFile = fopen(filename,"w");
        fprintf(SaveFile,"$25\n!0 0 0 0 0 0!0 0 0 0 0 0!0 0 0 0 0 0!0 0 0 0 0 0!0 0 0 0 0 0!0 0 0 0 0 0!0 0 0 0 0 0!0 0 0 0 0 0!0 0 0 0 0 0!0 0 0 0 0 0");
        fclose(SaveFile);
    }
    if(pickedslot==activeslot)
    {
        gold=25;
        memset(inventory,0,240);
    }
    return;
}

void SetTheFilesUpJustInCase()
{
    FILE* SaveFile;
    char filename[40] = {0};
    for(short i=0; i<3 ;i++)
    {
        sprintf(filename,"SaveFile%d.txt",i+1);
        SaveFile = fopen(filename,"a");
        fclose(SaveFile);
    }
}

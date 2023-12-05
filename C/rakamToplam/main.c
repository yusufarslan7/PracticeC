#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*klavyeden girilen herhangi bir sayýnýn rakamlarý toplamýný veren programý yazýnýz.*/
int main()
{
    long long int sayi=0,toplam=0;
    printf("sayi giriniz: ");
    scanf("%d",&sayi);
    while(sayi>0){
        toplam+=sayi%10;
        sayi/=10;
    }
    printf("%d",toplam);
return 0;
}

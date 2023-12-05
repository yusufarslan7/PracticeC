#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi,not,toplamNot=0,i=0;
    printf("Kisi sayisi giriniz: ");
    scanf("%d",&sayi);
    while(i<sayi)
    {
        printf(" %d. notu giriniz: ",i+1);
        scanf("%d",&not);
        if(not == -1){
            break;
        }
        toplamNot= toplamNot + not;
        i++;
    }
    if(i!=0)printf("Ortalama: %.2f", (float)toplamNot/i);
    else{
        printf("Deger girilmemistir.\n");
        main();
    }
    return 0;
}

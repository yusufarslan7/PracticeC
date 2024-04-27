#include <stdio.h>
#include <stdlib.h>
int toplam,sayi;
void main() {
       while(sayi % 2 == 0)
        {
            printf("Sayi giriniz: ");
            if (scanf("%d", &sayi) != 1) {
                printf("Gecersiz giris. Lutfen bir tam sayi girin.\n");
                while (getchar() != '\n');
                toplam = toplam - sayi;
                continue;
            }
            else{
                toplam= toplam + sayi;
            }
        }

    if(sayi %2 != 0)
    {   toplam = toplam - sayi;
        printf("Dongu sona erdi.\nToplam= %d\n",toplam);
    }
}

/*if(sayi % 2==0){
        toplam= toplam + sayi;
        main();
    }
    else{
        toplam= toplam + sayi;
        printf("Toplam: %d",toplam*/



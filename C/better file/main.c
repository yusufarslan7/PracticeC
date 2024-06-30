#include <stdio.h>
#include <stdlib.h>
#define DOSYA_YOLU "kayit.bin"

struct Ogrenci {
    char no[10];
    char ad[20];
    char soyad[20];
    int not;
    };

void listele();
void kayitlari_sil();

int main() {



    int secim;
    // Bundan sonra yazýlacaklar bu araya yazýlacak
    while (1) {
    printf("\n1: listele\n");
    printf("2: kayit ekle\n");
    printf("3: kayitlari sil\n");
    printf("0: cikis\n");
    printf("secim?: ");
    scanf("%d", &secim);
    switch (secim) {
        case 0:
        exit(0);
        case 1:
        listele();
        break;
        case 2: {
        struct Ogrenci ogr;
        printf("no ad soyad not?:");
        scanf("%s %s %s %d", ogr.no, ogr.ad, ogr.soyad, &ogr.not);
        kayit_ekle(ogr);
        break;
        }
        case 3: {
        kayitlari_sil();
        break;
        }
        default:
        printf("yalis secim\n");
        };
    }

    return 0;
}

void kayit_ekle(struct Ogrenci ogrenc) {
FILE * dosya;
// dosyayi okuma modunda ac
if ((dosya = fopen(DOSYA_YOLU, "a")) == NULL) {
printf("dosya acilamadi!\n");
exit(1);
}
fwrite(&ogrenc, sizeof(struct Ogrenci), 1, dosya);
fclose(dosya);
}


void listele() {
    FILE * dosya;
    if((dosya = fopen("kayit.bin","r"))== NULL){
        printf("dosya yok!\n");
        return;
    }
    struct Ogrenci ogrenc;
    printf("Liste: \n");
    while(1){
    size_t sayi = fread(&ogrenc,sizeof(struct Ogrenci),1,dosya);
    if(sayi < 1)break;
    printf("%s %s %s %d\n", ogrenc.no,ogrenc.ad,ogrenc.soyad,ogrenc.not);
    }
    fclose(dosya);
}

void kayitlari_sil() {
FILE * dosya;
// dosyayi yazma modunda ac
if ((dosya = fopen(DOSYA_YOLU, "w")) == NULL) {
printf("dosya acilamadi!\n");
exit(1);
}
// kapat
fclose(dosya);
}

/*
FILE * dosya;
// dosyayi okuma modunda ac
if ((dosya = fopen(DOSYA_YOLU, "r")) == NULL) {
printf("dosya yok!\n");
exit(1);
}
printf("\nliste:\n");
while (1) {
struct Ogrenci ogrenci;
size_t sayi = fread(&ogrenci, sizeof(struct Ogrenci), 1, dosya);
if (sayi < 1)
break; // okunamadiysa (dosya bitmisse vb.) donguyu durdur
printf("%s %s %s %d\n", ogrenci.no, ogrenci.ad, ogrenci.soyad, ogrenci.not);
}
fclose(dosya);
*/

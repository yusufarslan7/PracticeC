#include <stdio.h>
#include <stdlib.h>

#define DOSYA_YOLU "C:/Users/Yuars/Belgeler/GitHub/PracticeC/C/basicFileRead/hello.txt"


int main() {

    FILE * dosya;


    if ((dosya = fopen(DOSYA_YOLU, "r")) == NULL) {
        printf("dosya acilamadi!\n");
        exit(1);
    }

    fseek(dosya, 0, SEEK_END); // dosyanin sonuna atla

    long int len = ftell(dosya); // gostergenin bulundugu byte numarasini oku

    printf("dosyanin boyutu: %ld byte\n", len);

    fseek(dosya, 0, SEEK_SET); // dosya basina atla

    long int gosterge = ftell(dosya); // bulundugu byte numarasini oku

    printf("%ld. indexteki karakter okunacak\n", gosterge);

    char c = fgetc(dosya);

    printf("okunan karakter: %c\n\n", c);

    gosterge = ftell(dosya); // bulundugu byte numarasini oku

    printf("%ld. indexteki karakter okunacak\n", gosterge);

    c = fgetc(dosya);

    printf("okunan karakter: %c\n\n", c);

    fseek(dosya,len-2,SEEK_SET); // sondan iki onceki karaktere atla

    c = fgetc(dosya);

    printf("sondan iki onceki karakter: %c\n", c);

    fclose(dosya); // dosyayi kapat

    return 0;
}

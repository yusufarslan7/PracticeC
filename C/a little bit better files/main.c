#include <stdio.h>
#include <stdlib.h>
#define DOSYA_YOLU "test2.txt"
int main() {
FILE * dosya;
if ((dosya = fopen(DOSYA_YOLU, "w")) == NULL) { // dosyayi bastan yazmak icin ac (dosyanin icindekileri siler)
printf("dosya acilamadi!\n");
exit(1);
}
fputc('a', dosya); // a12 karkaterlerini tek tek yaz
fputc('1', dosya);
fputc('2', dosya);
fclose(dosya); // dosyayi kapat
if ((dosya = fopen(DOSYA_YOLU, "a")) == NULL) { // dosyayi eklemek icin ac
printf("dosya acilamadi!\n");
exit(1);
}
long int gosterge = ftell(dosya); // bulundugu byte numarasini oku
printf("%ld. indexteki karakter yazilacak\n", gosterge);
// yazma modunda fseek kullanilamaz. her zaman sona yazar.
fputs(" satir 1\n", dosya); // satir satir yaz
fputs("...\n", dosya);
fprintf(dosya, "%06d %.3f\notuz sekiz\n", 15, 1.3); // formatli yaz
fprintf(dosya, "test\n");
fclose(dosya); // dosyayi kapat

if((dosya = fopen(DOSYA_YOLU,"r"))== NULL){
    printf("dosya acilamadi!\n");
    exit(1);
}
char *BUF= (char*)malloc(100*sizeof(char));

fscanf(dosya,"%[^EOF]",BUF);
printf("\n\n");
puts(BUF);

free(BUF);
return 0;
}

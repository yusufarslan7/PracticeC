#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define DOSYA_YOLU "C:/Users/Yuars/Belgeler/GitHub/PracticeC/C/basicFileRead/hello.txt"


int main() {
FILE *dosya;
char *c;

c = malloc(sizeof(char)*100);
char *b;

b = malloc(sizeof(char)*100);
char *a;

a = malloc(sizeof(char)*100);

if ((dosya = fopen(DOSYA_YOLU, "r")) == NULL) {
printf("dosya acilamadi!\n");
exit(1);
}

/*
while ((c = fgetc(dosya)) != EOF) {
printf("%c",c);
}
*/

fscanf(dosya,"%[^!]!%s\n",c,b);
fscanf(dosya,"%s",a);

puts(a);
puts(b);
puts(c);

free(c);
free(b);
free(a);

fclose(dosya);
Sleep(1000);

return 0;
}

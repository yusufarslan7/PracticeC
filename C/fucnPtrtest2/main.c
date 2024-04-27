#include <stdio.h>
#include <stdlib.h>



int main()
{
    void bisiyazdir(void (*)(int));
    void aYazdir(int);
    void bYazdir(int);

    bisiyazdir(bYazdir);
    return 0;
}

void aYazdir(x)
{
    printf("%da",x);
}

void bYazdir(x)
{
    printf("%db",x);
}

void bisiyazdir(void (*yazdir)(int sayi))
{
    yazdir(10);
}

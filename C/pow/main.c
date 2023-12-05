#include <stdio.h>
#include <stdlib.h>

int sayi=4,kuvvet=2,sefer=1;

int main()
{
    if(sefer<kuvvet)
    {
        sefer++;
        return main()*sayi;
    }

    return sayi;
}

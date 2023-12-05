#include <stdio.h>
#include <stdlib.h>

int main()
{
    double wheat=1,total=0;

    for(int i=1;i<=64;i++){
        printf("%2d. basamaktaki pirinç sayisi: %20.0lf\n", i, wheat);
        total+=wheat;
        wheat*=2;
    }
    printf("\nBilgine verilecek toplam pirinc sayisi: %.0lf", total);
    return 0;
}

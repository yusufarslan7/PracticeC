#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayac = 1;
    while (sayac <= 10) {
    printf ("%s\n", sayac % 2 ? "****":"++++++++");
    ++sayac;
    }
return 0;
}

#include <stdio.h>
#include <stdlib.h>

float fah(int);

int main()
{
    int derece=0;

    while(derece<=100000)
    {
        printf("%3d Derece == %3.2f Fahrenheit\n",derece,fah(derece));
        derece++;
    }
    return 0;
}

float fah(a)
{
    return (a*1.8+32);
}

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x=3,y=3,z=3,t=3;
    y = x++ + x;
    z = t + t++;

    printf("%d %d",y,z);
}

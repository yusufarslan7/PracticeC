#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{   void* i;
    #pragma omp parallel
    while(1)
    {
        i= (char *)malloc(1);
    }
    return 0;
}

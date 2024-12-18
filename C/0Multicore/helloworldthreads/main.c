#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Thread %d: Hello World!\n", id);
    }
    return 0;
}

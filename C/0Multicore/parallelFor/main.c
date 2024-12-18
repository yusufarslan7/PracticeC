#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <pthread.h>

int main()
{
    int i,sum=0,thread_sum[16];

    //omp_set_num_threads(4);

    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        thread_sum[ID]=0;
        #pragma omp for
        for(i=1;i<=100;i++)
        {
            thread_sum[ID]+=i;
        }
    }
    for(i=0;i<16;i++)
    {
        sum+= thread_sum[i];
    }
    printf("Sum: %d",sum);
    return 0;
}

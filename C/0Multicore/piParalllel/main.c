#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main()
{
    static long num_steps = 10000000;
    double step;
    int i; double x,pi;
    long double sum_thread[16]={0},sum_real=0.0;
    step = 1/(double)num_steps;

    #pragma omp parallel
    {
        int ID= omp_get_thread_num();
        #pragma omp for
        for(i=0;i<num_steps;i++)
        {
            x = ((double)(i+0.5))*step;
            sum_thread[ID] += 4.0/(1.0+pow(x,2));
        }
    }
    for(i=0;i<16;i++)
    {
        sum_real+=sum_thread[i];
    }
    pi=step*sum_real;
    printf("%.16Lf",pi);

    return 0;
}

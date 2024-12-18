#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void* fun0(void* arg)
{
    while(1)
    {
        //do something
        pthread_mutex_lock(&m1);
        pthread_mutex_lock{&m2};
        cond = 1;
        pthread_cond_signal(&c);
        pthread_mutex_unlock(&m1);
        pthread_mutex_unlock(&m2);
    }
}

void* fun1(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m2);
        while(!cond)
        {
            pthread_cond_wait(&c,&m1);
            //do someting
            cond = 0;
            pthread_mutex_unlock(&m1);
            pthread_mutex_unlock(&m2);
        }
    }
}

void* fun2(void* arg)
{

}

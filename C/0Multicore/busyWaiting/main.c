#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int datas = 0;
int buffer;
char data_ready = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

void* producer(void*);
void* consumer(void*);


void consume_item(int item)
{
    printf("consuming item %d \n", item); fflush(stdout);
    Sleep(10);
}

int produce_item(void)
{
    ++datas;
    Sleep(1000);
    printf("producing %d\n",datas);fflush(stdout);
    return datas;
}

int main()
{
    pthread_t t1,t2;
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t2,NULL);
    pthread_join(t1,NULL);

    return 0;
}

void * consumer(void * arg)
{
    while(1)
    {
        pthread_mutex_lock(&m);
        while(data_ready == 0)
            pthread_cond_wait(&c,&m);
        int temp = buffer;
        data_ready = 0;
        pthread_mutex_unlock(&m);
        pthread_cond_signal(&c);
        consume_item(temp);
    }
}
void* producer(void* arg)
{
    while(1)
    {
        int temp = produce_item();
        pthread_mutex_lock(&m);
        buffer=temp;
        data_ready = 1;
        pthread_cond_signal(&c);
        //pthread_mutex_unlock(&m);
        //pthread_mutex_lock(&m);
        while(data_ready == 1)
            pthread_cond_wait(&c,&m);
        //pthread_cond_signal(&c);
        pthread_mutex_unlock(&m);
    }
}

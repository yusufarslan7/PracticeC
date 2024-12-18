/* Dining philosophers' problem with deadlock */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdbool.h>

#define NUM_PHIL 16

/*
Deadlock: program is blocked cuz of waiting.
Lifelock: program is blocked not cuz of waiting but cuz it rolls back to a certain point every time.

TIME FOR A BACKOFF STRAT:
-TAKE LEFT
-TRY RIGHT
-VOLL? DANN FREI LINKS
*/


pthread_mutex_t fork_locks[NUM_PHIL];

int exit_flag = 0;

void* philosopher(void* argc)
{

   int id = *((int*) argc);         // id of philosopher
   int left = id;                   // id of lock for left fork
   int right = (id + 1) % NUM_PHIL; // id of lock for right fork


   while(exit_flag == 0)
   {
       int first=0,second=0;
        if(id % 2 == 0){
            first = left;
            second = right;
        }
        else{
            first = right;
            second = left;
        }

    bool has_eaten = false;
    while(has_eaten == false){
      /* lock first fork */
      pthread_mutex_lock(&fork_locks[first]);
      //printf("Philosopher %d picked up first fork %d.\n", id, first);
      fflush(stdout);

      /* lock second fork */
      int ret = pthread_mutex_trylock(&fork_locks[second]);
      if(ret != EBUSY){
      //printf("Philosopher %d picked up second fork %d.\n", id, second);
      fflush(stdout);

      printf("Philosopher %d is eating.\n", id);
      fflush(stdout);
      has_eaten = true;

      /*unlock second fork */
      pthread_mutex_unlock(&fork_locks[second]);
      //printf("Philosopher %d put back second fork.\n", id);
      fflush(stdout);
        }
      /* unlock first fork */
      pthread_mutex_unlock(&fork_locks[first]);
      //printf("Philosopher %d put back first fork.\n", id);
      fflush(stdout);

      //printf("Philosopher %d is thinking.\n", id);
      fflush(stdout);
    }
   }
   return NULL;
}


int main(int argc, char** argv)
{
   int i = 0;

   // initialise the locks for all forks
   for(i = 0; i < NUM_PHIL; i++)
   {
      pthread_mutex_init(&fork_locks[i], NULL);
   }

   // create a thread for each philosopher
   pthread_t threads[NUM_PHIL];
   int ids[NUM_PHIL];
   for(i = 0; i < NUM_PHIL; i++)
   {
      ids[i] = i;
      pthread_create(&threads[i], NULL, philosopher, &ids[i]);
   }

   // wait for key press, then tell threads to exit
   getchar();
   exit_flag = 1;

   // wait for all threads
   for(i = 0; i < NUM_PHIL; i++)
   {
      pthread_join(threads[i], NULL);
   }

   // destroy the locks for the forks
   for(i = 0; i < NUM_PHIL; i++)
   {
      pthread_mutex_destroy(&fork_locks[i]);
   }

   return EXIT_SUCCESS;
}

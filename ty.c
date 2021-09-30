#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex, full, empty;
int buf[10];
int count=0;
void *prod(void *arg)
{
    if (*(int *)&full != 10)
    {
        int n = *(int *)arg;
        printf("Want to produce %i\n", count+1);
        sem_wait(&mutex);
        printf("producing %i\n", count+1);
        // sleep(2);
        sem_post(&mutex);
        printf("produced %i\n", count+1);
        sem_post(&full);
        sem_wait(&empty);
        count++;
    }
    else
    {
        printf("Full condition\n");
    }
}
void *consume(void *arg)
{
    if (*(int *)&empty < 10)
    {
        int n = *(int *)arg;
        printf("Want to consume %i\n", count);
        sem_wait(&mutex);
        printf("consuming %i\n", count);
        // sleep(2);
        sem_post(&mutex);
        printf("consumed %i\n", count);
        count--;
        sem_post(&empty);
        sem_wait(&full);
    }
    else
    {
        printf("Empty condition\n");
    }
}
int main()
{
    int np, nc;
    pthread_t buff[10];
    //for (int i = 0; i < 10; i++)
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 10);
    for (int i = 0; i < 10; i++)
       { pthread_create(&buff[i], NULL, prod, (void *)&i);
    // for (int i = 0; i < 10; i++)
        pthread_create(&buff[i], NULL, consume, (void *)&i);}
    for (int i = 0; i < 10; i++)
        pthread_join(buff[i], NULL);
}
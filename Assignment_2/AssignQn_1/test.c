
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include "prod_con.h"
#define Buf_size 5
#define MaxItems 5 


sem_t empty;
sem_t full;

int buffer[Buf_size];
pthread_mutex_t mutex;

int main()
{   

    pthread_t p[5],c[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,Buf_size);
    sem_init(&full,0,0);

    int num[5] = {1,2,3,4,5}; 

    for(int i = 0; i < 5; i++) {
        pthread_create(&p[i], NULL, (void *)producer, (void *)&num[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&c[i], NULL, (void *)consumer, (void *)&num[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(p[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(c[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
    
}

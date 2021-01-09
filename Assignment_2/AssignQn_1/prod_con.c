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

int in = 0;
int out = 0;

void *producer(void *pnum)
{   
    int item;
    //int in = 0;
    for(int i = 0; i < MaxItems; i++) 
    {
        if(in == Buf_size -1)
        	printf("Stack is full");
        item = rand()%10;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pnum),buffer[in],in);
        in = (in+1)%Buf_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cnum)
{   
    for(int i = 0; i < MaxItems; i++) 
    {
        if(in==out)
        	printf("Empty stack");
        //int out = 0;
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cnum),item, out);
        out = (out+1)%Buf_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}


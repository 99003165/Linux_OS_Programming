#include<stdio.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#include "func.h"


sem_t empty;
sem_t full;
pthread_mutex_t mutex;
# define MAX 5

int main()
{
	int item;
	
   	sem_init(&empty, 0, MAX);
    	sem_init(&full, 0, 0);
    	
    	pthread_mutex_init(&mutex, NULL);
    	
    	pthread_t pro,con;
    	pthread_create(&pro, NULL, producer, NULL);
    	pthread_create(&con, NULL, consumer, NULL);
    	
    	pthread_join(pro, NULL);
    	pthread_join(con, NULL);
    	
   	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
    	sem_destroy(&full);
	return 0;
}

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "func.h"

pthread_mutex_t mutex2;
# define MAX 5

int main()
{
	int item;
	
   	
    	pthread_mutex_init(&mutex2, NULL);
    	
    	pthread_t pro,con;
    	pthread_create(&pro, NULL, producer, NULL);
    	pthread_create(&con, NULL, consumer, NULL);
    	
    	pthread_join(pro, NULL);
    	pthread_join(con, NULL);
    	
   	pthread_mutex_destroy(&mutex2);
	
	return 0;
}

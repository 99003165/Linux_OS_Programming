#include<stdio.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>


pthread_mutex_t mutex1, mutex2;
# define MAX 5

int arr[MAX];
int front = -1;
int rear = -1;

void insert(int item)
{
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
		printf("Queue Overflows \n");
		return;
	}
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if(rear == MAX-1)
			rear = 0;
		else
			rear = rear+1;
	}
	
	arr[rear] = item ;
	printf("Element Added: %d\n",item);
}

void deletion()
{
	if(front == -1)
	{
		printf("Queue Empty\n");
		return ;
	}
	printf("Element Consumed : %d\n",arr[front]);
	
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		if(front == MAX-1)
			front = 0;
		else
			front = front+1;
	}
}

void* producer(void* pv)
{ 
	int item, i=0;
   	//pthread_mutex_lock(&mutex1);
   	  	
   	while(i<5){
   	
   	item = rand()%10;
   	pthread_mutex_lock(&mutex2);
  	insert(item);
  	sleep(1);
  	pthread_mutex_unlock(&mutex2);
  	sleep(1);
  	i++;}
   	//pthread_mutex_unlock(&mutex1);
  	
}
void* consumer(void* cv)
{
 	int j=0;
 	//pthread_mutex_lock(&mutex1);
 	
 	while(j<5){
 	pthread_mutex_lock(&mutex2);
  	deletion();
  	pthread_mutex_unlock(&mutex2);
  	sleep(1);
  	j++;}
   	//pthread_mutex_unlock(&mutex1);
	
}

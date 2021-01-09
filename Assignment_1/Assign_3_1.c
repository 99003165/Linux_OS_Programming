#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>
#include<stdint.h>

int sum=0;
int arr[100];

void* sum_thread(void* array)
{
	int *arr1=array;
	for(int i=0; i<10; i++)
	{	
		sum+= arr1[i];	
	}
	//printf("%d\n", sum);
	pthread_exit(NULL);
}

int main()
{	
	//int arr[100];
	//int *p ;
	//p=arr[0];
	for(int j=0; j<100; j++)
	{
		arr[j] = j;
		//printf("%d\n", arr[j]);
	}
	
	pthread_t pt1;
	
	int t=0;
	
	for(int i=0; i<10; i++)
	{
		pthread_create(&pt1,NULL,sum_thread, arr+t);
		t+=10;
		
	}						
	for(int i=0; i<10; i++)
	{
		pthread_join(pt1, NULL);
	}
	
	printf("Total sum of all the threads :%d\n", sum);
	
	return 0;
	
}
	

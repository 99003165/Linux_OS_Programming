#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>
#include<stdint.h>

int max_arr[10]={0};
int max=0;
int arr[100];

void* max_thread(void* array)
{
	int *arr1=array;
	for(int i=0; i<10; i++)
	{	
		if(arr1[i]>max)
			max = arr1[i];	
	}
	//printf("%d\n", sum);
	pthread_exit(NULL);
}

int main()
{	
	
	for(int j=0; j<100; j++)
	{
		arr[j] = j;
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
	
	for(int x=0; x<10; x++)
	{
			
	}	
	printf("Total sum of all the threads :%d\n", sum);
	
	return 0;
	
}
	

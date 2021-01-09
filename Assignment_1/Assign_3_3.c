#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

void* timefn(void* pv)
{
	while(1)
	{
		time_t curnt_time;
		time(&curnt_time);
		printf("%s", ctime(&curnt_time));
		sleep(1);
	}
}


int main()
{
	pthread_t p1;
	
	pthread_create(&p1, NULL,timefn ,NULL);
	
	pthread_join(p1,NULL);
	return 0;
}

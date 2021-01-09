#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int pid;
	char opt;
	printf("Enter the pid: ");
	scanf("%d",&pid);
	printf("Enter the signal option: ");
	scanf("%s",&opt);
	
	switch(opt)
	{
		case 'a': printf("Abort the process");
			  kill(pid, 6);
			  break;
		case 'i': printf("Interrupt the process");
			  kill(pid, 2);
			  break;
		case 'k': printf("Kill the process");
			  kill(pid, 9);
			  break;
		case 'q': printf("Quit the process");
			  kill(pid, 3);
			  break;
		default:;
	}
	return 0;
}

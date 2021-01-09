/*2. Write a program to compile & link any c/c++ program within child process by launching gcc using execl/execlp.*/

#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>


int main()
{
	int ret,status;
	ret=fork();
		
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{ 
    		execl("/bin/gcc","gcc","examp.c","-o","out.out","examp.o",NULL) ; 
	}
	else	
	{
		waitpid(ret, &status, 0); 
	}
	exit(0);
}


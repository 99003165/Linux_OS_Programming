/*3. Write a program to build multifile program using fork & exec as follows
   * There are multiple source files holding some functions
   * Create multiple child processes to compile each source file (execl/execlp)
   * On successful completion, launch another child process for linking
   * On successful linking, launch another child process for executing */
   
 
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	int ret1, ret2,ret3, ret4, exec1, exec2, exec3, exec4, status;
	
	ret1 = fork();
	if(ret1<0)
	{
		perror("Child process 1");
		exit(1);
	}
	if(ret1==0)
	{ 
    		//exit(1);
    		execl("/bin/gcc","gcc","-c","sum.c",NULL) ;    		
	}
	else	
	{	
		waitpid(ret1, &status, 0);
	}
	
	ret2 = fork();
	if(ret2<0)
	{
		perror("Child process 2");
		exit(3);
	}
	if(ret2==0)
	{ 
    		execl("/bin/gcc","gcc","-c","main.c",NULL) ; 
	}
	else	
	{
		waitpid(ret2, &status, 0); 
	}
	
	ret3 = fork();
	if(ret3<0)
	{
		perror("Child process 3");
		exit(5);
	}
	if(ret3==0)
	{ 
    		execl("/bin/gcc","gcc","-o","out.out","main.o","sum.o",NULL) ;
	}
	else	
	{
		waitpid(ret3, &status, 0); 
	}
	
	ret4 = fork();
	if(ret4<0)
	{
		perror("Child process 4");
		exit(7);
	}
	if(ret4==0)
	{ 
    		execl("out.out","./out.out",NULL) ;
	}
	else	
	{
		waitpid(ret4, &status, 0); 
	}
	
	exit(0);
}

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{	
	int fd1,fd2;
	
	fd1=open("sample1.txt",O_RDONLY, 0777);
	if(fd1<0)
	{
		perror("open");
		exit(1);
	}
	
	int maxlen=128;
	char buffer[maxlen];
	
	read(fd1,buffer,maxlen);
			
	fd2=open("sample2.txt",O_WRONLY|O_CREAT, 0777);
	
	if(fd2<0)
	{
		perror("open");
		exit(2);
	}
	
	write(fd2, buffer, strlen(buffer));
	close(fd2);
	close(fd1);
	
	return 0;	//exit(0);
}


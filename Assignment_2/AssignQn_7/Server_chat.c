
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<linux/stat.h>

#define FIFO_FILE "MYPIPE"

int main()
{
   	FILE *fp;
  	char Msg[40];
	char Read_Buffer[80];
   	umask(0);
   	mknod(FIFO_FILE,S_IFIFO|0666,1);
   	while(1)
   	{
      		fp=fopen(FIFO_FILE,"r");
      		fgets(Read_Buffer,80,fp);
      		
      		printf("Client : %s\n", Read_Buffer);
     		fclose(fp);
      		sleep(1);
      		
      		printf("Server : ");
      		gets(Msg);
      		fp=fopen(FIFO_FILE,"r+");
      		if(Msg[strlen(Msg)-1]=='.')
      		{
         		fputs(Msg,fp);
         		fclose(fp);
         		return 0;
      		}
      		
      		fputs(Msg,fp);
      		fclose(fp);
      		sleep(1);
      	}
   	return 0;
}


/*7. Write a program to implement simple chat application between two processes using
   named pipes (FIFOs)
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h> 
#include<linux/stat.h>

#define FIFO_FILE "MYPIPE"  /*create MYPIPE pipe before executin mkfifo MYPIPE*/

int main()
{
	FILE *fp;
	char Msg[40];
	char Read_Buffer[80];
   
while(1)
   {
      if((fp = fopen(FIFO_FILE,"r+"))==NULL)
      {
         perror("fopen");
         exit(1);
      }
      printf("Client Send: ");
      gets(Msg);
      
      if(Msg[strlen(Msg)-1]=='.')
      {
           fputs(Msg, fp);
           fclose(fp);
           return 0;
      }
      fputs(Msg,fp);
      fclose(fp);
      sleep(1);
      
      fp=fopen(FIFO_FILE,"r");
      fgets(Read_Buffer,80,fp);
      printf("Server : %s\n",Read_Buffer);
      fclose(fp);
      sleep(1);
    }
   return 0;
}


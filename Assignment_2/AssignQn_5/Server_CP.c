/*5. Implement a simple client-server scenario using message queues
   * Client process send requested command over message queue
   * Server process receives requested command over message queue and executes in a child 	    process using execl/execlp
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

struct MessageBuffer
{
   long Message_type;
   char Message[100];
} Msg;

int main() 
{
	key_t MyKey;
   	int Msg_Id;
   	int ret, status;
   	MyKey = ftok("progfile", 65); 
   
  	Msg_Id = msgget(MyKey, 0666 | IPC_CREAT); 
   	msgrcv(Msg_Id, &Msg, sizeof(Msg), 1, 0); 
  
  	printf("Received Command is : %s \n", Msg.Message);
  	ret = fork();
  	
  	if(ret<0)
  	{
  		perror("Child process : ");
  		exit(1);
  	}
  	else if(ret == 0)
  	{
  		execl("/bin/sh","sh","-c",Msg.Message,NULL);
  	}
	else
	{
		waitpid(ret, &status, 0);
	} 
   	return 0;
}

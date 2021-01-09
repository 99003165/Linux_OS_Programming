/*4. Implement a simple client-server scenario using message queues
  * Client process send a string over message queue
  * Server process toggles the string and send back to client.
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct MessageBuffer
{
   long Message_type;
   char Message[100];
} Msg;

int main() 
{
	key_t MyKey;
   	int Msg_Id;
   
   	MyKey = ftok("progfile", 65); 
   
  	Msg_Id = msgget(MyKey, 0666 | IPC_CREAT); 
   	msgrcv(Msg_Id, &Msg, sizeof(Msg), 1, 0); 
  
  	printf("Received Message is : %s \n", Msg.Message);
	printf("Write Message : ");
	fgets(Msg.Message, 100, stdin);
  
   	msgsnd(Msg_Id, &Msg, sizeof(Msg), 0); 
   
   	printf("Sent message is : %s \n", Msg.Message);
   	return 0;
}

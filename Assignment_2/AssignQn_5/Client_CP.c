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
   Msg.Message_type = 1;
   printf("Enter command to be executed: ");
   
   fgets(Msg.Message, 100, stdin);
   
   msgsnd(Msg_Id, &Msg, sizeof(Msg), 0); 
   msgrcv(Msg_Id, &Msg, sizeof(Msg), 1, 0); 
  
   printf("Received Message is : %s \n", Msg.Message);

   return 0;
}

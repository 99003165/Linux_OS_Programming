all: Server_IPC.c Client_IPC.c
	gcc Server_IPC.c Client_IPC.c -c

client: Client_IPC.c
	gcc Client_IPC.c -o client.out

server: Server_IPC.c
	gcc Server_IPC.c -o server.out


clean:
	rm -rf *.o all.out



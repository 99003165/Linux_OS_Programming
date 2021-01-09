

all: Server_CP.c Client_CP.c
        gcc Server_IPC.c Client_IPC.c -c

client: Client_CP.c
        gcc Client_CP.c -o client.out

server: Server_IPC.c
        gcc Server_CP.c -o server.out


clean:
        rm -rf *.o all.out




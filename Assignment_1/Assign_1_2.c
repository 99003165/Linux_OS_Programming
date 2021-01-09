#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd,nbytes;
    int word_count=0, line_count=0, ch_count=0;
	fd=open("second.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
    
    int leng = 256;
    char buffer[leng], a[leng];
   
    read(fd, buffer, leng);
    //printf("Buffer %s", buffer);
    for (int i = 0; i < strlen(buffer); i++)    //line count
    {
        if(buffer[i] == '\n')
            line_count++;
    }
    line_count++;
    
    for (int i = 0; i < strlen(buffer); i++)    //character count
    {
        if(buffer[i] != EOF)
            ch_count++;
    }

    for (int i = 0; i < strlen(buffer); i++)    //word count
    {
        if(buffer[i] == ' ' | buffer[i] == '\t' | buffer[i] == '\n' | buffer[i] == '\0')
            word_count++;
    }
    word_count++;
    
    printf("Line count:%d", line_count);
    printf("Line count:%d", ch_count);
    printf("Line count:%d", word_count);
}
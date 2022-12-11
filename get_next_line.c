#include "get_next_line.h"
#include <stdio.h>
char *get_next_line(int fd)
{
    int file;
    char *filename = "data.txt";
    char *data;

    file = open(filename,O_RDONLY);

    if(file < 0)
    {
        return (NULL);
    }

    int bytesRead = read(file,data,strlen(fd));

    data = malloc(sizeof(char) * strlen(data));

    printf(" data uzunluk :%d",strlen(data));

    return(bytesRead);

    close(file);
}

int main()
{
    int file = open("data.txt",O_RDONLY);
    printf("%d",get_next_line(file));
    
}
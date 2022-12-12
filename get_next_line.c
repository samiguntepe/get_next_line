#include "get_next_line.h"
#include <stdio.h>
char *get_next_line(int fd)
{
    int file;
    char *filename = "data.txt";
    static char *data;
    int i;
    int bytesRead;
    file = open(filename,O_RDONLY);
    if(BUFFER_SIZE < 0)
        return (NULL);
    if(file < 0)
        return (NULL);
    data = malloc(BUFFER_SIZE * sizeof(char));
        bytesRead = read(file,data,BUFFER_SIZE);
    if(bytesRead < 0)
        return(NULL);
    return(data);
}

int main()
{
    int file = open("data.txt",O_RDONLY);
    
    printf("%s",get_next_line(file));
    close(file);
}
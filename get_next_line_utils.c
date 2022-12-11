#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t fdlen(int fd)
{
    char line[100];
    size_t size;

    if (fd == -1) {
        return (NULL);
    }

    if (read(fd, line, sizeof(line)) != -1)
    {
        size = ft_strlen(line);
        return(size);
    }  

    close(fd);
}
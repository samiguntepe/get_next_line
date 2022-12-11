#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE sizeof(char)
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

char *get_next_line(int fd);
size_t fdlen(int fd);
size_t	ft_strlen(const char *s);

#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char *get_next_line(int fd);
int count_line(char *data);

#endif

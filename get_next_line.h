#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

/* Eğer buffer boyutu tanımlanmamışsa, varsayılan olarak 5 ata */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

/* Gerekli kütüphaneleri dahil et */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* ft_strlen fonksiyonu, bir dizinin uzunluğunu döndürür */
size_t ft_strlen(char *s);

/* ft_strchr fonksiyonu, bir dizide bir karakterin ilk görüldüğü indisi döndürür */
char *ft_strchr(char *s, int c);

/* ft_strjoin fonksiyonu, iki diziyi birleştirir ve yeni bir dizi oluşturur */
char *ft_strjoin(char *left_str, char *buff);

/* ft_get_line fonksiyonu, bir dizideki ilk satırı alır */
char *ft_get_line(char *left_str);

/* ft_new_left_str fonksiyonu, bir diziden bir satır çıkardıktan sonra kalanını döndürür */
char *ft_new_left_str(char *left_str);

/* get_next_line fonksiyonu, bir dosyadaki her bir satırı okur ve döndürür */
char *get_next_line(int fd);

#endif
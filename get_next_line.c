/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:53:44 by sguntepe          #+#    #+#             */
/*   Updated: 2022/12/15 20:25:13 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_to_left_str(int fd, char *left_str)
{
char *buff;
int rd_bytes;

/* buff dizisini heap'te bellekte yer ayır ve işaretçiyi döndür */
buff = malloc((BUFFER_SIZE + 1) * sizeof(char));

/* Eğer yer ayrılamadıysa, NULL döndür */
if (!buff)
	return (NULL);

/* Okunan bayt sayısını 1'e atandı çünkü bu değer okunan bayt sayısının aşağıdaki döngü içinde
kontrol edildiği için koşulun dışında kalmasını sağlar ve dosyada veri olmadığı zaman byte değeri
0 olacağı için döngü başlamaz o yüzden byte değerini 1 verildi*/
rd_bytes = 1;

/* Eğer left_str dizisi içinde '\n' karakteri yoksa ve okunan bayt sayısı 0 değilse döngüye gir */
while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
{
	/* Dosyadan BUFFER_SIZE kadar veri oku ve rd_bytes değişkenine ata */
	rd_bytes = read(fd, buff, BUFFER_SIZE);

	/* Eğer dosyadan veri okunamadıysa, bellekte ayırdığımız yeri serbest bırak ve NULL döndür */
	if (rd_bytes == -1)
	{
		free(buff);
		return (NULL);
	}

	/* buff dizisinin son elemanına '\0' karakterini ata */
	buff[rd_bytes] = '\0';

	/* left_str ve buff dizilerini birleştir ve left_str değişkenine ata */
	left_str = ft_strjoin(left_str, buff);
}

/* buff dizisini serbest bırak */
free(buff);

/* left_str dizisini döndür */
return (left_str);
}

char *get_next_line(int fd)
{
char *line;
static char *left_str;
/* Eğer dosya tanımlayıcısı geçersiz veya buffer boyutu sıfırdan küçükse, 0 döndür */
if (fd < 0 || BUFFER_SIZE <= 0)
	return (0);

/* ft_read_to_left_str fonksiyonu kullanılarak dosyadaki kalan veriyi oku ve left_str değişkenine ata */
left_str = ft_read_to_left_str(fd, left_str);

/* Eğer dosyada veri kalmadıysa, NULL döndür */
if (!left_str)
	return (NULL);

/* ft_get_line fonksiyonu kullanılarak dosyadaki bir satırı al ve line değişkenine ata */
line = ft_get_line(left_str);

/* ft_new_left_str fonksiyonu kullanılarak dosyadaki kalan veriyi al ve left_str değişkenine ata */
left_str = ft_new_left_str(left_str);

/* Okunan satırı döndür */
return (line);
}
// #include <stdio.h>
// int main()
// {
// 	int file = open("data.txt",O_RDONLY);
// 	printf("%s",get_next_line(file));
// }

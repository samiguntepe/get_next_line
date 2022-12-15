#include "get_next_line.h"

size_t ft_strlen(char *s)
{
size_t i;

/* İndisi 0'a ata */
i = 0;

/* Eğer s dizisi geçersizse, 0 döndür */
if (!s)
	return (0);

/* s dizisinin son elemanına kadar döngüye gir */
while (s[i] != '\0')

	/* İndisi bir arttır */
	i++;

/* s dizisinin uzunluğunu döndür */
return (i);
}

char *ft_strchr(char *s, int c)
{
  // Dizinin boyutunu tutan bir değişken
  int i = 0;

  // Eğer dizi boş ise 0 döndür
  if (!s)
  	return 0;

  // Eğer aranan karakter \0 ise, dizinin sonuna git
  if (c == '\0')
  	return (char *)&s[ft_strlen(s)];

  // Dizi elemanlarını tek tek kontrol et
  while (s[i] != '\0')
  {
    // Eğer eleman karakterle eşleşiyorsa adresini döndür
    if (s[i] == (char) c)
		return (char *) &s[i];
    i++;
  }

  // Eğer karakter bulunamazsa 0 döndür
  return 0;
}

char *ft_strjoin(char *left_str, char *buff)
{
  // Dizi elemanlarını saymak için kullanılan değişkenler
  size_t	i;
	size_t	j;

  // Oluşturulacak yeni dizi
  char *str;

  // Eğer left_str boşsa, 1 elemanlı bir dizi oluştur
  if (!left_str)
  {
    left_str = (char *) malloc(1 * sizeof(char));
    left_str[0] = '\0';
  }

  // Eğer left_str veya buff boşsa, NULL döndür
  if (!left_str || !buff) return NULL;

  // Yeni dizinin boyutunu hesapla ve bellekten yer ayır
  str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));

  // Eğer bellekten yer ayrılamazsa, NULL döndür
  if (str == NULL) return NULL;

  // left_str elemanlarını yeni diziye kopyala
  i = -1;
  j = 0;
  if (left_str)
    while (left_str[++i] != '\0')
      str[i] = left_str[i];

  // Buff dizisinin elemanlarını yeni diziye kopyala
  while (buff[j] != '\0')
    str[i++] = buff[j++];

  // Dizinin sonuna '\0' koy
  str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';

  // left_str serbest bırak
  free(left_str);

  // Oluşturulan dizinin adresini döndür
  return (str);
}

char *ft_get_line(char *left_str)
{
  // Dizi elemanlarını saymak için kullanılan değişken
  int i;

  // Oluşturulacak yeni dizi
  char *str;
 
  // Eğer left_str boşsa, NULL döndür
  i = 0;
  if (!left_str[i]) return NULL;

  // '\n' karakterine kadar geç
 
  while (left_str[i] && left_str[i] != '\n')
    i++;

  // Yeni diziyi oluştur ve bellekten yer ayır
  str = (char *) malloc(sizeof(char) * (i + 2));
  if (!str)
    return NULL;

  // left_str'nin '\n' karakterine kadar olan kısmını yeni diziye kopyala
  i = 0;
  while (left_str[i] && left_str[i] != '\n')
  {
    str[i] = left_str[i];
    i++;
  }

  // Eğer left_str '\n' karakterine sahip ise, yeni diziye de kopyala
  if (left_str[i] == '\n')
  {
    str[i] = left_str[i];
    i++;
  }

  // Dizinin sonuna '\0' koy
  str[i] = '\0';

  // Oluşturulan dizinin adresini döndür
  return (str);
}

char *ft_new_left_str(char *left_str)
{
  // Dizi elemanlarını saymak için kullanılan değişkenler
  int	i;
  int	j;

  // Oluşturulacak yeni dizi
  char *str;
  i = 0;
  // left_str'de '\n' karakterine kadar olan kısmı geçer
  while (left_str[i] && left_str[i] != '\n')
  	i++;

  // Eğer '\n' karakteri yoksa, left_str'yi serbest bırak ve NULL döndür
  if (!left_str[i])
  {
    free(left_str);
    return NULL;
  }

  // Yeni diziyi oluştur ve bellekten yer ayır
  str = (char *) malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
  if (!str)
  	return NULL;

  // '\n' karakterinden sonraki kısmı yeni diziye kopyala
  j = 0;
  i++;
  while (left_str[i])
    str[j++] = left_str[i++];

  // Dizinin sonuna '\0' koy
  str[j] = '\0';

  // left_str'yi serbest bırak
  free(left_str);

  // Oluşturulan dizinin adresini döndür
  return str;
}


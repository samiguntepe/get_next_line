#include <unistd.h> // read() fonksiyonu için gerekli kütüphane
#include <stdlib.h> // malloc() fonksiyonu için gerekli kütüphane
#include <fcntl.h>  // open() fonksiyonu için gerekli kütüphane

#define BUFFER_SIZE 1024 // tampon bellek boyutu

int main() {
    // dosya işaretçisi
    int fd;
    // dosya aç
    fd = open("dosya.txt", O_RDONLY);
    if (fd == -1) {
        // dosya açılamadıysa hata mesajı vererek çık
        return NULL;
    }

    // tampon bellek alanını ayır
    char* buffer = (char*) malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        // tampon bellek alanı ayrılamadıysa hata mesajı vererek çık
        return NULL;
    }

    // dosya sonuna kadar oku
    while (read(fd, buffer, BUFFER_SIZE) > 0) {
        // okunan verileri ekrana yaz
        printf("%s", buffer);
    }

    // tampon bellek alanını serbest bırak
    free(buffer);

    // dosyayı kapat
    close(fd);

    return 0;
}

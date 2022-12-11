#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char line[100];

    fd = fcntl(fileno(stdin), F_DUPFD);
    if (fd == -1) {
        perror("Dosya açılamadı!");
        return 1;
    }

    if (read(fd, line, sizeof(line)) != -1) {
        printf("Ilk satırın uzunluğu: %lu\n", strlen(line));
    }

    close(fd);
    return 0;
}

// writer.c - sends data to FIFO
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char message[100];

    // Open the FIFO for writing
    fd = open("myfifo", O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    write(fd, message, sizeof(message));
    close(fd);

    printf("Message sent successfully.\n");
    return 0;
}

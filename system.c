#include <fcntl.h>      // for open, fcntl
#include <unistd.h>     // for read, write, close
#include <stdio.h>      // for printf, perror
#include <stdlib.h>     // for exit

int main() {
    int fd1, fd2;          // file descriptors
    char buffer[1024];     // buffer to store data temporarily
    ssize_t bytesRead;     // number of bytes read

    // Open source file for reading
    fd1 = open("source.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("Error opening source file");
        exit(1);
    }

    int flags = fcntl(fd1, f_getfl);
    if (flags < 0) {
        perror("fcntl error");
        return 1;
    }
    // Open (or create) destination file for writing (truncate if it exists)
    fd2 = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("Error opening destination file");
        close(fd1);
        exit(1);
    }

    // Read from source and write to destination
    while ((bytesRead = read(fd1, buffer, sizeof(buffer))) > 0) {
        write(fd2, buffer, bytesRead);
    }

    // Close both files
    close(fd1);
    close(fd2);

    printf("File copied successfully using system calls.\n");
    return 0;
}

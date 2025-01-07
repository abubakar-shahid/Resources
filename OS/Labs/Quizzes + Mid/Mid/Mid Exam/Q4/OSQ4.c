#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define FIFO_FILE "my_pipe"
int main() {
    int fd;
    char message[80];

    mkfifo(FIFO_FILE, S_IFIFO | 0666);
    fd = open(FIFO_FILE, O_RDONLY);
    
    close(fd);
    fd = open(FIFO_FILE, O_WRONLY);
    close(fd);
    return 0;
}

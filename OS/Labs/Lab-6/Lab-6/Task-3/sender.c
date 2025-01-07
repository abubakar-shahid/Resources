#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"

int main() {
    int fd;
    char message[80];
    char result[80];

    // Create the FIFO (named pipe) if it doesn't exist
    mkfifo(FIFO_FILE, S_IFIFO | 0666);

    // Open the FIFO for writing
    printf("Enter operator and two operands (e.g., + 4 10): ");
    fgets(message, sizeof(message), stdin);
    fd = open(FIFO_FILE, O_WRONLY);

    // Send the message to the worker
    
    write(fd, message, strlen(message) + 1);

    // Close the write end of the FIFO
    close(fd);

    // Open the FIFO for reading the result from the worker
    fd = open(FIFO_FILE, O_RDONLY);
    read(fd, result, sizeof(result));
    close(fd);

    printf("Received result from worker: %s\n", result);

    return 0;
}


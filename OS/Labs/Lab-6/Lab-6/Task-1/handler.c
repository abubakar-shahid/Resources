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
    char inputMessage[80];

    // Create the FIFO (named pipe) if it doesn't exist
    mkfifo(FIFO_FILE, S_IFIFO | 0666);

    printf("Enter a message to send to case_changer: ");
    fgets(inputMessage, 80, stdin);

    // Open the FIFO for writing
    fd = open(FIFO_FILE, O_WRONLY);
    write(fd, inputMessage, strlen(inputMessage) + 1);
    close(fd);

    // Open the FIFO for reading the response from case_changer
    fd = open(FIFO_FILE, O_RDONLY);
    char outputMessage[80];
    read(fd, outputMessage, sizeof(outputMessage));
    close(fd);

    printf("Received from case_changer: %s\n", outputMessage);

    return 0;
}


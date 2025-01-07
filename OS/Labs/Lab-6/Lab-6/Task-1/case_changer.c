#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h> 
#define FIFO_FILE "myfifo"

void changeCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            if (islower(str[i])) {
                str[i] = toupper(str[i]);
            } else {
                str[i] = tolower(str[i]);
            }
        }
    }
}

int main() {
    int fd;
    char receivedMessage[80];

    // Open the FIFO for reading
    fd = open(FIFO_FILE, O_RDONLY);
    read(fd, receivedMessage, sizeof(receivedMessage));
    close(fd);

    // Change the case of the received message
    changeCase(receivedMessage);

    // Open the FIFO for writing the modified message
    fd = open(FIFO_FILE, O_WRONLY);
    write(fd, receivedMessage, strlen(receivedMessage) + 1);
    close(fd);

    return 0;
}


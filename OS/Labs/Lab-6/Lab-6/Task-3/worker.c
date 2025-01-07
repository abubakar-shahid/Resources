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
    char operator;
    int operand1, operand2;
    char result[80];

    // Create the FIFO (named pipe) if it doesn't exist
    mkfifo(FIFO_FILE, S_IFIFO | 0666);

    // Open the FIFO for reading
    fd = open(FIFO_FILE, O_RDONLY);

    // Read the message from the sender
    read(fd, message, sizeof(message));

    // Parse the message into operator and operands
    sscanf(message, "%c %d %d", &operator, &operand1, &operand2);

    // Calculate the result based on the operator
    switch (operator) {
        case '+':
            sprintf(result, "%d", operand1 + operand2);
            break;
        case '-':
            sprintf(result, "%d", operand1 - operand2);
            break;
        case '*':
            sprintf(result, "%d", operand1 * operand2);
            break;
        case '/':
            if (operand2 != 0) {
                sprintf(result, "%.2f", (float)operand1 / operand2);
            } else {
                strcpy(result, "Division by zero is not allowed.");
            }
            break;
        default:
            strcpy(result, "Invalid operator.");
    }

    // Close the read end of the FIFO
    close(fd);

    // Open the FIFO for writing the result to the sender
    fd = open(FIFO_FILE, O_WRONLY);
    write(fd, result, strlen(result) + 1);
    close(fd);

    return 0;
}


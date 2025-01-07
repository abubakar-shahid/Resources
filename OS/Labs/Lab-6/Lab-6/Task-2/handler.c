#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_FILE "myfifo"

int main() {
    int fd;
    int num_of_elements_in_array = 5; // Change this to the desired number of elements
    int send_array[] = {1, 2, 3, 4, 5};
    int recv_array[num_of_elements_in_array];
    int size = sizeof(int) * num_of_elements_in_array;

    // Create the FIFO (named pipe) if it doesn't exist
    mkfifo(FIFO_FILE, S_IFIFO | 0666);

    // Open the FIFO for writing
    fd = open(FIFO_FILE, O_WRONLY);
    write(fd, send_array, size);
    close(fd);

    // Sleep to allow the calculator process to read and process
    sleep(2); // Adjust the sleep duration as needed

    // Open the FIFO for reading the result
    fd = open(FIFO_FILE, O_RDONLY);
    read(fd, recv_array, size);
    close(fd);

    printf("Received sum from calculator: ");
    int sum = 0;
    for (int i = 0; i < num_of_elements_in_array; i++) {
        printf("%d ", recv_array[i]);
        sum += recv_array[i];
    }
    printf("= %d\n", sum);

    return 0;
}


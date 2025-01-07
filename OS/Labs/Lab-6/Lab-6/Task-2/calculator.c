#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_FILE "myfifo"

int main() {
    int fd;
    int num_of_elements_in_array = 5; // Change this to match the handler's array size
    int send_array[num_of_elements_in_array];
    int recv_array[num_of_elements_in_array];
    int size = sizeof(int) * num_of_elements_in_array;

    // Create the FIFO (named pipe) if it doesn't exist
    mkfifo(FIFO_FILE, S_IFIFO | 0666);

    // Open the FIFO for reading
    fd = open(FIFO_FILE, O_RDONLY);
    read(fd, send_array, size);
    close(fd);

    // Calculate the sum
    int sum = 0;
    for (int i = 0; i < num_of_elements_in_array; i++) {
        sum += send_array[i];
    }

    // Sleep to ensure synchronization with the handler process
    sleep(1); // Adjust the sleep duration as needed

    // Open the FIFO for writing the result
    fd = open(FIFO_FILE, O_WRONLY);
    write(fd, &sum, sizeof(int));
    close(fd);

    return 0;
}


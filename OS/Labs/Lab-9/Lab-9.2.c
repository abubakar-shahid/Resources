#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key, SHM_SIZE, 0666);

    if (shmid == -1) {
        perror("Error opening shared memory segment");
        exit(EXIT_FAILURE);
    }

    char *shmaddr = shmat(shmid, (void *)0, 0);
    if (shmaddr == (char *)(-1)) {
        perror("Error attaching shared memory");
        exit(EXIT_FAILURE);
    }

    int sum = 0, count = 0;
    char *ptr = shmaddr;

    while (*ptr != '\0') {
        int number = atoi(ptr);
        sum += number;
        count++;
        while (*ptr != ',' && *ptr != '\0') {
            ptr++;
        }
        if (*ptr == ',') {
            ptr++; // Move past the comma
        }
    }

    if (count > 0) {
        printf("Server: Sum = %d, Average = %.2f\n", sum, (float)sum / count);
    } else {
        printf("Server: No data found in shared memory.\n");
    }

    shmdt(shmaddr);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

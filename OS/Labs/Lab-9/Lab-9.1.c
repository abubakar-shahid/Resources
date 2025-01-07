#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    key_t key = ftok("shmfile",65);
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("Error creating shared memory segment");
        exit(EXIT_FAILURE);
    }

    char *shmaddr = shmat(shmid, (void *)0, 0);
    if (shmaddr == (char *)(-1)) {
        perror("Error attaching shared memory");
        exit(EXIT_FAILURE);
    }

    ssize_t bytesRead = read(fd, shmaddr, SHM_SIZE);
    if (bytesRead == -1) {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }

    printf("Client: Data read from file and written to shared memory.\n");

    shmdt(shmaddr);
    close(fd);

    return 0;
}

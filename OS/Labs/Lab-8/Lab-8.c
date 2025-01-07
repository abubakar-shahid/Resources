#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <sys/wait.h>

#define BUFFER_SIZE 20

// Shared memory buffer structure
struct SharedMemory 
{
    char data[BUFFER_SIZE];
    sem_t empty;
    sem_t full;
    sem_t mutex;
};

void producer(const char *filename, struct SharedMemory *buffer) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        perror("fopen");
        exit(1);
    }

    while (1) 
    {
        sem_wait(&buffer->empty);
        sem_wait(&buffer->mutex);

        int bytesRead = fread(buffer->data, 1, BUFFER_SIZE, file);
        if (bytesRead <= 0) 
        {
            buffer->data[0] = '$'; // Indicate end of file
        }

        sem_post(&buffer->mutex);
        sem_post(&buffer->full);

        if (buffer->data[0] == '$') 
        {
            break; // End of file
        }
    }

    fclose(file);
}

void consumer(struct SharedMemory *buffer) 
{
    while (1) 
    {
        sem_wait(&buffer->full);
        sem_wait(&buffer->mutex);

        if (buffer->data[0] == '$') 
        {
            sem_post(&buffer->mutex);
            break; // End of file
        }

        printf("Consumer: %s\n", buffer->data);
        getchar(); // Wait for the user to press Enter

        sem_post(&buffer->mutex);
        sem_post(&buffer->empty);
    }
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        exit(1);
    }

    key_t key = ftok("shmfile", 65); // Create a unique key for shared memory
    int shmid = shmget(key, sizeof(struct SharedMemory), IPC_CREAT | 0666);
    struct SharedMemory *buffer = (struct SharedMemory *)shmat(shmid, NULL, 0);

    // Initialize semaphores
    sem_init(&buffer->empty, 1, 1);
    sem_init(&buffer->full, 1, 0);
    sem_init(&buffer->mutex, 1, 1);

    pid_t pid = fork();

    if (pid < 0) 
    {
        perror("fork");
        exit(1);
    } 
    else if (pid == 0) 
    {
        consumer(buffer);
    } 
    else 
    {
        producer(argv[1], buffer);
        waitpid(pid, NULL, 0); // Wait for the child process to finish

        // Cleanup and remove shared memory and semaphores
        shmdt(buffer);
        shmctl(shmid, IPC_RMID, NULL);
        sem_destroy(&buffer->empty);
        sem_destroy(&buffer->full);
        sem_destroy(&buffer->mutex);
    }

    return 0;
}
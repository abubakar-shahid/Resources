#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t child_pid;
    char input_str[1024];

    // Create the pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Failed to create pipes");
        return 1;
    }

    // Fork a child process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Failed to fork child process");
        return 1;
    }

    else if (child_pid > 0){
        printf("In Parent Process!\n");
        close(pipe1[0]);
        close(pipe2[1]);

        char output_str[1024];
        int fd_1 = open("file.txt", O_RDONLY);
        int fd_2 = open("updated.txt", O_WRONLY);

        int reader;
        while((reader = read(fd_1, input_str, sizeof(input_str))) > 0){
            write(pipe1[1], input_str, reader);
        }
        close(fd_1);
        while((reader = read(pipe2[0], output_str, sizeof(output_str))) > 0){
            write(fd_2, output_str, reader);
        }
        close(fd_2);

        close(pipe1[1]);
        close(pipe2[0]);
    }

    else {
        printf("In Child Process!\n");

        close(pipe2[0]);
        close(pipe1[1]);

        char input_str[1024];
        char output_str[1024];
        int reader = read(pipe1[0], input_str, sizeof(input_str));

        // Modify the message by removing special characters
        int i, j;
        for(i = 0, j = 0; i < reader; i++){
            if (input_str[i] != '&' && input_str[i] != '@' && input_str[i] != '#' && input_str[i] != '%' && input_str[i] != '*' && input_str[i] != '?' &&  input_str[i] != '$' && input_str[i] != '"' && input_str[i] != '~') {
                output_str[j] = input_str[i];
                j++;
            }
        }

        reader = write(pipe2[1], output_str, reader);
        close(pipe1[0]);
        close(pipe2[1]);

        exit(0);
    }
}

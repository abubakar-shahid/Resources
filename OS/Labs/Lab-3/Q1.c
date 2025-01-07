#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();    
    if (pid == 0) {
        int a = 10;
        printf("In Child Process, Variable a = %d", a);
        printf("\n");
    }
    else if (pid > 0) {
        printf("In Parent Process!\n");
    }
    else {
        printf("Fork did not Work!\n");
    }
    return 0;
}

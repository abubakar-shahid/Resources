#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void sortArray(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[10];
    printf("Enter the elements of array: ");
    int i;
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sortArray(arr, 10);
        printf("In Child Process!!!\n");
        printf("Sorted Array Elements: ");
        for (i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nChild Process ID: %d\n", getpid());
    }
    else if (pid > 0) {
        // Parent process
        printf("Parent Process ID: %d\n", getpid());
    }
    else {
        printf("Fork failed\n");
        return 1;
    }
    return 0;
}

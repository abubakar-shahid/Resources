#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int arr[], int size, int isAscending) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if ((isAscending && arr[j] > arr[j + 1]) || (!isAscending && arr[j] < arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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
    pid_t child1, child2;
    child1 = fork();
    if (child1 == 0) {
        printf("I am Child 1 (with ID: %d and Parent ID: %d", getpid(), getppid());
        sortArray(arr, 10, 1);
        printf("): ");
        printArray(arr, 10);
        exit(0);
    }
    else {
        child2 = fork();
        if (child2 == 0) {
            printf("I am Child 1 (with ID: %d and Parent ID: %d", getpid(), getppid());
            sortArray(arr, 10, 0);
            printf("): ");
            printArray(arr, 10);
            exit(0);
        }
        else {
            wait(NULL);
            wait(NULL);
            printf("Process Terminating and my ID: %d and Parent ID: %d", getpid(), getppid());
            printf("\n");
            exit(0);
        }
    }
}

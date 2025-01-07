#include <stdio.h>
#include <pthread.h>

void *printSeries(void* limit){
    int num1 = 0, num2 = 1;
    int next = num1 + num2;
    int i = 0;
    printf("Fibonacci Series: %d, %d", num1, num2);
    while(next<=*((int*)limit)){
        printf(", %d", next);
        num1 = num2;
        num2 = next;
        next = num1 + num2;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    /*int limit;
    printf("Enter the limit of terms: ");
    scanf("%d", &limit);
    int array[limit];
    printf("Enter the elements of array:-\n");
    for(int i=0;i<limit;i++){
        scanf("%d", &array[i]);
    }*/
    pthread_t th[argc-1];
    for(int i=1;i<argc;i++){
        int n = atoi(argv[i]);
        pthread_create(&th[i-1], NULL, printSeries, &n);
        pthread_join(th[i-1], NULL);
        //printSeries(array[i]);
        //printf("\n");
    }

    return 0;
}


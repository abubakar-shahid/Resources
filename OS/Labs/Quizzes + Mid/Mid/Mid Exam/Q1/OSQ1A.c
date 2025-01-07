#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int depth;
    printf("Enter the specified depth: ");
    scanf("%d", &depth);
    int i;
    for(i=0;i<depth;i++){
        if(!fork()){
            printf("in child, my id: %d, parent id: %d\n", getpid(), getppid());
            fork();
        }
        else{
            wait(NULL);
        }
    }
    printf("ended\n");
    return 0;
}

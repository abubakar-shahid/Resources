#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    
    int p[2];
    if(pipe(p)==-1){
        printf("error creating pipe!\n");
        return 0;
    }
    if(fork()){
        printf("In Parent Process!, Writing message...\n");
        close(p[0]);
        write(p[1], "Welcome to FAST!\n", 25);
        close(p[1]);
    }
    else{
        printf("In Child Process!, Reading mssage from parent: ");
        char st[100];
        close(p[1]);
        read(p[0], st, sizeof(st));
        printf("%s", st);
        close(p[0]);
    }
    return 0;
}

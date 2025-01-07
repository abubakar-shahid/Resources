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
        close(p[0]);
        write(p[1], "Message sent from parent!", 25);
        close(p[1]);
    }
    else{
        char st[100];
        close(p[1]);
        read(p[0], st, sizeof(st));
        printf("%s\n", st);
        close(p[0]);
    }
    return 0;
}

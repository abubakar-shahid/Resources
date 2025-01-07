#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){

    char str1[100];
    char str2[100];

    pid_t pid=fork();


    if(pid==0){
        //In Child Process
        int fd_1 = open("input.txt", O_RDONLY);
        int fd_2 = open("output.txt", O_WRONLY);

        int reader;
        int x=0;
        while((reader = read(fd_1, str1, sizeof(str1))) > 0){
            printf("taking input\n");
            str1[x]=reader;
            x++;
        }
        close(fd_1);

        int i;
        for(i=0;str1[i]!=',';i++){
            str2[i]=str1[i];
        }
        i+=2;
        int flag=1;
        int j;
        for(j=0;str1[i]!='\n';i++,j++){
            if(str1[i]!=str2[j]){
                printf("breaking!!!\n");
                flag=0;
                break;
            }
        }

        if(flag==1){        
            printf("Strings Equal!\n");
            while((reader = read(fd_2, str1, sizeof(str1))) > 0){
                write(fd_2, str1, reader);
            }
            close(fd_2);
        }

        else{
            printf("Strings Not Equal!");
        }
    }

    return 0;
}

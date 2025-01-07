#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char store[255];
    FILE* filePointer = fopen("data.txt", "r");
    fscanf(filePointer, "%s", store);
    printf("%s", store);
    
    fgets(store, 255, (FILE*)filePointer);
    printf("%s", store);
    
    fgets(store, 255, (FILE*)filePointer);
    printf("%s\n", store);
    
    fclose(filePointer); 
}

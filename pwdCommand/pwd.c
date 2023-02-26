#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 1024

int main(){

    char *path = ((char *)malloc(sizeof(char)*100));

    char *return_path = getcwd(path, BUFFER);
    if (return_path != NULL) {
        printf("your new directory %s\n", return_path);
    }

    return 0;
}
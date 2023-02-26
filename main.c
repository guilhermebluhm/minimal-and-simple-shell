#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER 1024

int qtd_espacos(char *str){
    int espacos = 0;
    while(*str){
        if (*str == ' '){
            espacos++;
        }
        str++;
    }
    return espacos;
}



int main() {

    char *path = ((char *)malloc(sizeof(char)*BUFFER));
    char saida = 'n';
    char *return_path = NULL;
    char aux_cd[1024];

    //mostrar cada uma

    while (true) {
        setvbuf(stdin, NULL, _IOLBF, BUFFER);
        printf("command: ");
        gets(path);

        strcpy(aux_cd, &path[0]);
        char *token_extracao = strtok(path," ");


        if (strcmp(path, "pwd") == 0) {
            return_path = getcwd(path, BUFFER);
            if (return_path != NULL) {
                printf("your current path is: %s\n", return_path);
            }
        }

        else if(strcmp(token_extracao, "cd") == 0){

            int qtd_strings = qtd_espacos(aux_cd) + 1, i = 0;
            char strings[qtd_strings][strlen(aux_cd)];
            char *pch = strtok (aux_cd," ");
            while (pch != NULL) {
                strcpy(strings[i++], pch);
                pch = strtok(NULL, " ");
            }

            if(chdir(strings[1]) == 0){

                return_path = getcwd(path, BUFFER);
                if (return_path != NULL) {
                    printf("your new directory %s\n", return_path);
                }

            }
        }
        else if(strcmp(token_extracao,"fork") == 0){
           char *args[] = {"pwdCommand/pwdCommand2",NULL};
           size_t f = fork();
            if(f == 0){
                printf("i m child process for pwd command (pid process %llu)\n",getpid());
                execvp(args[0],args);
            }
        }
        else {
            printf("impossivel\n");
        }
        printf("\nsair: ");
        scanf(" %c",&saida);
        getchar(); //remove o \n no final
        if(saida == 'y' || saida == 's'){
            break;
        }
        free(path);
    }
    return 0;
}
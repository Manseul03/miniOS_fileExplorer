#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "system.h"
void print_minios(char* str);

int main() {
    print_minios("[MiniOS SSU] Hello, World!");

    char *input;

    while(1) {
        // readline을 사용하여 입력 받기
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input,"exit") == 0) {
            break;
        }
	else if (strcmp(input,"minisystem") == 0){
            minisystem();
        }
        else if (strcmp(input,"dicegame") == 0){
            dicegame();
        }
        else if (strcmp(input, "file") == 0){
            fileExplorer();
        }
        else if (strcmp(input, "file search") == 0){
            filesearch(NULL, NULL);
        }
        else if (strcmp(input, "create folder") == 0){
            createFolder();
        }
        else if (strcmp(input, "delete folder") == 0){
            deleteFolder();
        }
        else if (strcmp(input, "copy file") == 0){
            copyFile();
        }
        else system(input);
    }

    // 메모리 해제
    free(input);
    print_minios("[MiniOS SSU] MiniOS Shutdown........");

    return(1);
}

void print_minios(char* str) {
        printf("%s\n",str);
}

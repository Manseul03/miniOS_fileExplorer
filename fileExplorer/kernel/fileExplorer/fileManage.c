#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define CHAR_SIZE 100

// 폴더 생성 함수
void createFolder() {
    char create_input[CHAR_SIZE];
    //create_input = readline("enter name of folder to create ");
    printf("enter name of folder to create: ");
    fgets(create_input, sizeof(create_input), stdin);
    
    printf("working...");
    if (mkdir(create_input, 0777) == 0) {
        printf("폴더 생성 성공: %s\n", create_input);
    } else {
        printf("폴더 생성 실패: %s\n", create_input);
    }
}

// 폴더 삭제 함수
void deleteFolder() {
    char delete_input[CHAR_SIZE];
    //delete_input = readline("enter name of folder to delete ");
    printf("enter name of folder to create: ");
    fgets(delete_input, sizeof(delete_input), stdin);
    
    printf("working...");
    if (rmdir(delete_input) == 0) {
        printf("폴더 삭제 성공: %s\n", delete_input);
    } else {
        printf("폴더 삭제 실패: %s\n", delete_input);
    }
}

// 파일 복사 함수
void copyFile() {
    char *sourceFileName;
    char *destinationFileName;
    FILE *sourceFile, *destinationFile;
    char ch;
    
    sourceFileName = readline("enter the file name you want to copy to the full path");
    sourceFileName = readline("enter the destination you want to copy as the full path");
    
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("원본 파일을 열 수 없음: %s\n", sourceFileName);
        free(sourceFileName);
        free(destinationFileName);
        return;
    }

    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("대상 파일을 생성할 수 없음: %s\n", destinationFileName);
        fclose(sourceFile);
        free(sourceFileName);
        free(destinationFileName);
        return;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("파일 복사 성공: %s -> %s\n", sourceFileName, destinationFileName);
    fclose(sourceFile);
    fclose(destinationFile);
    
    free(sourceFileName);
    free(destinationFileName);
}


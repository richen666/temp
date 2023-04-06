/*
 * @Date: 2022-10-26 22:50:56
 * @LastEditors: cyf
 * @LastEditTime: 2023-02-25 16:10:57
 * @FilePath: /cyf/test_codes/test_fork.c
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // int pid = fork();
    // fork();
    // fork();
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", i);
    // }
    // printf("\n");

    // if(pid < 0) exit(1);
    // #ifndef DEBUG
    // if(pid == 0) {
    //     printf("Child, %d\n", getpid());
    // }
    // #else
    // if(pid > 0) {
    //     printf("Parent, %d\n", getpid());
    // }
    // #endif

    // printf("Hello, world.\n");
    // if(pid == 0) {
    //     printf("Child arrive here?\n");
    // }
    // else {
    //     printf("Parent arrive here?\n");
    // }
    // printf("Parent or Child?\n");
    // exit(0);

    for(int i = 0; i < 3; ++i) {
        int pid = fork();
        if(pid < 0) {
            perror("fork");
            exit(1);
        }
        if(pid > 0) {
            // printf("Parent %d\n", getpid());
            continue;
            // break;
        }
        if(pid == 0) {
            printf("Parent %d Child %d\n", getppid(), getpid());
            // return 0;
            // exit(0);
        }
    }

    printf("Who arrive here? [ %d ]\n", getpid());
    // wait((int*)0);
    while(1);
    // exit(0);
}
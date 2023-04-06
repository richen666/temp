/*
 * @Date: 2022-10-26 14:49:22
 * @LastEditors: cyf
 * @LastEditTime: 2022-10-26 17:27:56
 * @FilePath: /cyf/test_codes/test_array.c
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    int arr[10];
    printf("size of array is %ld\n", sizeof(arr)/sizeof(int));

    int brr[] = {1, 3, 5};
    int idx = 0, cnt = 0, *ptr = brr;
    while(*ptr != '\0') {
        ++cnt; ++idx;
        ++ptr;
    }
    printf("size of brr is %d\n", cnt);

    int pipfd[2];
    if(pipe(pipfd) == -1){
        perror("pipe");
        exit(1);
    }
    // int sndBuf[10] = {1, 4, 2};
    int sndBuf[10] = {1, 4}, rcvBuf[10];
    int pid = fork();
    if(pid < 0) {
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        sleep(3);
        close(pipfd[1]);
        int ret = read(pipfd[0], rcvBuf, 10);
        printf("read %d bytes: ", ret);
        for(int i = 0; i < 10; ++i) {
            if(rcvBuf[i] != '\0')
                printf("%d", rcvBuf[i]);
        }
        printf("\n");
    }else {
        close(pipfd[0]);
        // write(pipfd[1], sndBuf, 4 * 3);
        write(pipfd[1], sndBuf, 4 * 2);
    }
    return 0;
}
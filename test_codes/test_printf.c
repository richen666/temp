/*
 * @Date: 2022-11-03 14:17:26
 * @LastEditors: cyf
 * @LastEditTime: 2022-11-03 15:10:07
 * @FilePath: /cyf/test_codes/test_printf.c
 */
#include <stdio.h>
#include <stdlib.h>

void mystery(int n) {
    n += 5;
    n /= 10;
    printf("%s\n", "**********" + 10 - n);
}

int main(int argc, char* argv[]) {
    // mystery(*argv[1] - '0');
    // mystery(100);
    mystery(atoi(argv[1]));
    // printf("hello, world\n");
}
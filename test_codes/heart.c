/*
 * @Date: 2022-11-11 11:40:23
 * @LastEditors: cyf
 * @LastEditTime: 2022-11-11 11:44:45
 * @FilePath: /cyf/test_codes/heart.c
 */
#include <stdio.h>
#define C(a) ((a)*(a)*(a))

int main() {
    int x, y;

    for(y = 9; y > -6; y--) {
        for(x = -8; x < 9; ++x) {
            putchar(C (x*x+y*y-25) < 25*x*x*y*y*y ? "*##*"[(x+10)%4] : '-');
        }
        putchar('\n');
    }

    return 0;
}
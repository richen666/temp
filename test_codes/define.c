/*
 * @Date: 2022-07-27 14:35:37
 * @LastEditors: cyf
 * @LastEditTime: 2022-11-25 23:32:02
 * @FilePath: /cyf/test_codes/define.c
 */
// #define concat_temp(x, y) x ## y
// #define concat(x, y) concat_temp(x, y)

// #define CHOOSE2nd(a, b, ...) b

// // original version, still right
// // there is no comma between contain_comma and a, rather than a blank, but it's right
// // if the parameter called macro as shown below isn't defined when it's empty, finally the function called CHOOSE2nd() is CHOOSE2nd(p     a, b), whose result is empty for there is nothing between p and a.
// #define MUX_WITH_COMMA(contain_comma, a, b) CHOOSE2nd(contain_comma a, b)
// // on th contrary, it's wrong, because finally the function called CHOOSE2nd() is CHOOSE2nd(p, a, b), it still return the "a" as a return value.
// // #define MUX_WITH_COMMA(contain_comma, a, b) CHOOSE2nd(contain_comma, a, b)

// #define MUX_MACRO_PROPERTY(p, macro, a, b) MUX_WITH_COMMA(concat(p, macro), a, b)

// #define __P_DEF_0  X,
// #define __P_DEF_1  X,
// #define __P_ONE_1  X,
// #define __P_ZERO_0 X,

// #define MUXDEF(macro, X, Y)  MUX_MACRO_PROPERTY(__P_DEF_, macro, X, Y)

// // simplification for conditional compilation
// #define __IGNORE(...)
// #define __KEEP(...) __VA_ARGS__
// // keep the code if a boolean macro is defined
// #define IFDEF(macro, ...) MUXDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)
// #define TEST
// // #define concat(x,y) x ## y
// #define NUMBERS 1, \
//                 2, \
//                 3, \
//                 4

#define PRINT(FORMAT, VALUE) \
        printf("The value is " FORMAT " \n", VALUE)
#define MAX(a,b)          (a) > (b)? (a) : (b)
#define SQUARE(x)         (x)*(x)
#define DOUBLE(x)         ((x)+(x))

#include <stdio.h>

void test() {
    printf("Now here is a test.\n");
}

int main() {
    // IFDEF(TEST, test());
    // int input= concat(6, 6);
    // printf("%d\n", input);
    // PRINT(%d, 10);
    // printf("%d", 10);
    // const char* h = "hello", *w = "world";
    // printf("%s\n", concat(h,w));
    // int x[] = { NUMBERS };
    // for(int i =  0; i < sizeof(x) / sizeof(int); ++i) {
    //     printf("%d\n", x[i]);
    // }

    int x, y, z;
    y = 2; z = 3;
    x = MAX(y,z);
    printf("%d, %d, %d\n", x, y, z);

    y = 2; z = 3;
    x = MAX(++y, ++z);
    printf("%d, %d, %d\n", x, y, z);

    x = 2;
    y = SQUARE(x);
    z = SQUARE(x+6);
    printf("%d, %d, %d\n", x, y, z);

    x = 2;
    y = 3;
    z = MAX(5*SQUARE(x), ++y);
    printf("%d, %d, %d\n", x, y, z);

}

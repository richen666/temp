/*
 * @Date: 2022-11-19 20:20:13
 * @LastEditors: cyf
 * @LastEditTime: 2022-11-19 23:17:23
 * @FilePath: /cyf/test_codes/strtok.c
 */
#include <string.h>
#include <stdio.h>

void print_token(char *line) {
    static char* whitespace = " \t\f\r\v\n";
    static char* semicolon = ";";
    char *token;
    token = strtok(line, semicolon);
    for(; token != NULL; token = strtok(NULL, semicolon)) {
        printf("arrive here?\n");
        printf("Next token is %s\n", token);
    }
}

int main() {
      char *file =
    //   char file[] =
	  "#######\n"
	  "#######\n"
	  "#     #\n";

    char file_array[100];
    strcpy(file_array, file);
    printf("%s\n", file_array);

    //   char *str = "aaabbb\nccccdddff\nttffrr\t";
      char *str2 = "aaa;bbb;ccc";

   char str[80] = "This is - www.runoob.com - website";
//    const char s[2] = "\n";
   const char* s = "\n";
    char* saveptr = NULL;
    // static char* semicolon = ";";
    // char *token = strtok(file, s);
    char *token = strtok_r(file, s, &saveptr);
    // for(; token != NULL; token = strtok(NULL, s)) {
    for(; token != NULL; token = strtok_r(NULL, s, &saveptr)) {
        // printf("arrive here?\n");
        printf("Next token is %s\n", token);
    }

    //   print_token(str);
    //   print_token(file);
    // print_token(str2);

}
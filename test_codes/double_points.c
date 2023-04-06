/*
 * @Date: 2022-07-14 00:41:20
 * @LastEditors: cyf
 * @LastEditTime: 2022-11-19 20:24:16
 * @FilePath: /cyf/test_codes/double_points.c
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char **board = (char**)malloc(5*sizeof(char*));
	//char **board = (char**)malloc(sizeof(char*));
	//
	printf("%ld\n", sizeof(board));
	for(int i = 0; i < 5; ++i) {
		board[i] = malloc(20 * sizeof(char));
		strcpy(board[i], "Is a problem?");
	}

	printf("%ld\n", sizeof(board));
	for(int i = 0; i < 5; ++i) {
		printf("%s\n", board[i]);
	}
	//strcpy(*board, "Is a problem?");
	//printf("%s\n", board[0]);

	//char *board[] = malloc(sizeof(char));
	//char board[];

	// segmentfault
	//char *board;
	//strcpy(board, "");
	//strcpy(board, "Is a problem?");
	//printf("%s\n", board);

	char *file =
	  "#######\n"
	  "#######\n"
	  "#     #\n";
	printf("%s", file);
}


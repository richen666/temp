/*
 * @Date: 2022-10-27 15:51:25
 * @LastEditors: cyf
 * @LastEditTime: 2022-10-27 18:08:49
 * @FilePath: /cyf/test_codes/test_primes2.c
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

int sieve(int *parent) {
    close(parent[1]);
    int prime;
    if (read(parent[0], &prime, sizeof(int)) == 0){
        close(parent[0]);
        exit(0);
    }
    fprintf(stdout, "prime %d\n", prime);
    int childfd[2];
    if(pipe(childfd) == -1){
        fprintf(stderr, "pipe: cannot create pipe\n");
        exit(1);
    }
    int pid = fork();
    if(pid < -1){
        fprintf(stderr, "fork: cannot create process\n");
        exit(1);
	}
    if(pid == 0){
        close(parent[0]);
        sieve(childfd);
    } else {
        close(childfd[0]);
        int num;
        while(read(parent[0], &num, sizeof(int)) > 0){
            if(num % prime){
                write(childfd[1], &num, sizeof(int));
            }
        }
        close(parent[0]);
        close(childfd[1]);
        wait(NULL);
        exit(0);
    }
    exit(0);
}

int main(int argc, char* argv[]) {
	int parentfd[2];
	if(pipe(parentfd) == -1){
		fprintf(stderr, "pipe: cannot create pipe\n");
		exit(1);
	}

	int pid = fork();
	if(pid < -1){
		fprintf(stderr, "fork: cannot create process\n");
        close(parentfd[0]);
        close(parentfd[1]);
		exit(1);
	}
	if(pid > 0){
		close(parentfd[0]);
		for(int num = 2; num <= 35; ++num){
			write(parentfd[1], &num, sizeof(num));
		}
		close(parentfd[1]);
        wait(NULL);
	}
    else {
		sieve(parentfd);
	}
	exit(0);
}
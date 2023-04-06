/*
 * @Date: 2022-10-26 17:27:23
 * @LastEditors: cyf
 * @LastEditTime: 2022-10-27 15:36:59
 * @FilePath: /cyf/test_codes/test_primes.c
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

int
Fork_And_Pass(int *nums, int length)
{
	if(length <= 0) exit(1);

	// int len = 0;
	// while(*ptr != '\0'){
	// while(len < length) {
	// 	printf("%d ", *(nums+len));
	// 	++len;
	// }
	// printf("\n");

	int sublength = length >> 1;
	int pipefd[2], divide = 0;

	if(pipe(pipefd) == -1){
		// fprintf((FILE*)STDERR_FIlengthO, "pipe: cannot create pipe\n");
		perror("pipe");
		exit(1);
	}

	int pid = fork();
	if(pid < 0){
		// fprintf((FILE*)STDERR_FIlengthO, "fork: cannot create process\n");
		perror("fork");
		exit(1);
	}

	if(pid > 0){
		close(pipefd[0]);
		// int idx = 0, sndBuf[sublength];
		for(int i = 0; i < length; ++i){
			// if(nums[i] != 0 && divide == 0){
			if(divide == 0) {
				// fprintf((FILE*)STDOUT_FIlengthO, "prime %d\n", nums[i]);
				printf("prime %d\n", nums[i]);
				divide = nums[i];
			}
			if(nums[i] % divide){
				// *(sndBuf+idx) = nums[i];
				// ++idx;
				write(pipefd[1], &nums[i], sizeof(nums[i]));
			}
		}
		divide = 0;
		close(pipefd[1]);
		// write(pipefd[1], sndBuf, idx * 4);
	// }
	}else{
		// sleep(5);
		close(pipefd[1]);
		int rcvBuf[sublength], num, idx = 0;
		// while(read(pipefd[0], rcvBuf, subLen) > 0) {
		while (read(pipefd[0], &num, sizeof(num)) > 0){
			// Fork_And_Pass(rcvBuf);
			rcvBuf[idx++] = num;
		}
		Fork_And_Pass(rcvBuf, idx);
		close(pipefd[0]);
	}
	exit(0);
}

int
main(int argc, char* argv[])
{
	int arr[35];
	for(int i = 0; i < 34; ++i){
		arr[i] = i + 2;
	}
	int len = sizeof(arr)/sizeof(arr[0]);
	Fork_And_Pass(arr, len);
	// sleep(10);
	exit(0);
}

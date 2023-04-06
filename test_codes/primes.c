/*
 * @Date: 2022-10-26 21:12:41
 * @LastEditors: cyf
 * @LastEditTime: 2022-10-27 15:49:20
 * @FilePath: /cyf/xv6-labs-2022/user/primes.c
 */
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
Fork_And_Pass(int *nums, int length)
{
	if(length <= 0) exit(1);
	int subLength = length >> 1;

	int pipefd[2], divide = 0;

	if(pipe(pipefd) == -1){
		fprintf(2, "pipe: cannot create pipe\n");
		exit(1);
	}

	int pid = fork();
	if(pid < 0){
		fprintf(2, "fork: cannot create process\n");
		exit(1);
	}

	if(pid > 0){
		close(pipefd[0]);
		for(int i = 0; i < length; ++i){
			if(divide == 0){
				fprintf(1, "prime %d\n", nums[i]);
				divide = nums[i];
			}
			if(nums[i] % divide){
				write(pipefd[1], &nums[i], sizeof(nums[i]));
			}
		}
		divide = 0;
		close(pipefd[1]);
	} else {
		close(pipefd[1]);
		int rcvBuf[subLength], num, idx = 0;
		while (read(pipefd[0], &num, sizeof(num)) > 0){
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
	exit(0);
}

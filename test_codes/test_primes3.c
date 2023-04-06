#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

void sieve(int* parent);
//we have two pipe: parent[2], child[2]
int main(int argc, char *argv[])
{
    int status;
    int parent[2];//create a pipe
    pipe(parent);

    if (fork() < 0) //fork error
    {
        fprintf(stderr, "fork error\n");
        exit(0);
    }
    if (fork() == 0) {// child process
        sieve(parent);// child process begin sieve
    }
    close(parent[0]);//close parent read port
    for (int i = 2; i <= 11; i++) {
        write(parent[1], &i, sizeof(int)); //write numbers into pipe
    }
    close(parent[1]); //close wiring of parent
    wait(&status);  //wait for all child process to end
    exit(0);
}

void sieve(int* parent)
{
    close(parent[1]);
    int ans;
    // read parent and  write it into n
    // if there is nothing to read, this child process can go die
    if (read(parent[0], &ans, sizeof(int)) == 0)
    {
        close(parent[0]);
        exit(0);
    }
    printf("prime %d\n",ans);
    int child[2];
    pipe(child);
    if (fork() == 0) // child process continue sieve
    {
        close(parent[0]);
        sieve(child); //start a new child process
    }
    close(child[0]);
    int prime = ans;
    while (read((parent[0]), &ans, sizeof(int)) != 0) {
        if (ans%prime != 0) {// is prime
            write(child[1], &ans, sizeof(int));
        }
    }
    close(parent[0]);
    close(child[1]);  //close writing of parent
    wait((int *)0);
    exit(0);
}

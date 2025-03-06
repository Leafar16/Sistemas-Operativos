#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>  // Biblioteca necessária para wait()


int main(int argc, char* argv[]) {
    int pid;
    int i;

    if ((pid = fork()) == 0) { // Child process
        printf("[child] pid: %d\n", getpid());
        printf("[child] parent pid: %d\n", getppid());
        printf("[child] child pid: %d\n", pid);
        
        i=5;
        _exit(0);

    } else { // Parent process
        //wait(NULL); // Keep the parent alive
        i=7;
        printf("[parent] pid: %d\n", getpid());
        printf("[parent] parent pid: %d\n", getppid());
        printf("[parent] child pid: %d\n", pid);
    }

    printf("i:%d\n",i);
    return 0;
}

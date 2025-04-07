#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    int N = argc - 1;  // Number of commands
    int pid[N];

    for (int i = 0; i < N; i++) {
        if ((pid[i] = fork()) == 0) { 
            execlp(argv[i + 1], argv[i + 1], NULL);
            perror("execlp failed");
            _exit(1);  
        }
    }

    // Parent waits for all child processes
    for (int i = 0; i < N; i++) {
        int status;
        waitpid(pid[i], &status, 0);
        if (WIFEXITED(status)) {
            printf("Process %d exited with status %d\n", pid[i], WEXITSTATUS(status));
        } else {
            printf("Process %d terminated abnormally\n", pid[i]);
        }
    }

    return 0;
}
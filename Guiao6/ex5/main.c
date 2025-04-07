#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    

    int pipefd[2];

    pipe(pipefd);

   //ls
   if (fork() == 0) {
        close(pipefd[0]);
        
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        
        execlp("ls", "ls", "/etc", NULL);
        _exit(1);
    }

    close(pipefd[1]);

    //wc
    if (fork() == 0) {
        
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        
        execlp("wc", "wc","-l", NULL);
        _exit(1);
    }

    close(pipefd[0]);
    wait(NULL);
    wait(NULL);


    return 0;
}
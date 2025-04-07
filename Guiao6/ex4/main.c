#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    

    int pipefd[2];

    pipe(pipefd);

    if (fork() == 0) {

        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);

        close(pipefd[0]);

        execlp("wc", "wc", NULL);
        
        _exit(1);
    }

    char buffer[1024];
    int read_bytes=0;

    while((read_bytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
        write(pipefd[1], buffer, read_bytes);
    }

    close(pipefd[1]);

    wait(NULL);

    write(STDOUT_FILENO, "FIM\n", 5);


    return 0;
}
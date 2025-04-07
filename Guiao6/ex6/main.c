//grep -v ˆ# /etc/passwd | cut -f7 -d: | uniq | wc -l
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int pipefd1[2];
    int pipefd2[2];
    int pipefd3[2];

    pipe(pipefd1);
    pipe(pipefd2);
    pipe(pipefd3);

    // grep
    if (fork() == 0) {
        close(pipefd1[0]);
        
        dup2(pipefd1[1], STDOUT_FILENO);
        close(pipefd1[1]);

        execlp("grep", "grep", "-v", "^#", "/etc/passwd", NULL);
        _exit(1);
    }
    //cut
    close(pipefd1[1]);
    if (fork() == 0) {
        dup2(pipefd1[0], STDIN_FILENO);
        close(pipefd1[0]);
        dup2(pipefd2[1], STDOUT_FILENO);
        close(pipefd2[1]);
        execlp("cut", "cut", "-f7", "-d:", NULL);
        _exit(1);
    }
    close(pipefd1[0]);
    close(pipefd2[1]);
    // uniq
    if (fork() == 0) {
        dup2(pipefd2[0], STDIN_FILENO); // Use the read end of pipefd2
        dup2(pipefd3[1], STDOUT_FILENO); // Use the write end of pipefd3
        close(pipefd2[1]);
        close(pipefd3[0]);
        execlp("uniq", "uniq", NULL);
        _exit(1);
    }
    close(pipefd2[0]);
    close(pipefd3[1]);

    // wc
    if (fork() == 0) {

        dup2(pipefd3[0], STDIN_FILENO);
        close(pipefd3[0]);

        execlp("wc", "wc", "-l", NULL);
        _exit(1);
    }
    close(pipefd3[0]);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char*argv){

    int out_fd= open ("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);


    dup2(out_fd, 1);
    close(out_fd);

    if (fork() == 0) {
        execlp("ls", "ls", NULL);
        _exit(1);

    } 

    wait(NULL);
    
    return 0;
}
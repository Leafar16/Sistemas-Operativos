#include <stdio.h>
#include  <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    //stdin (0)-> teclado

    //stdout (1)-> tela

    //stderr (2)-> tela

    int in_fd=open("/etc/passwd", O_RDONLY | O_CREAT, 0644);

    int out_fd=open("saida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    int err_fd=open("erros.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    //check errors
    int stdout_original=dup(1);

    dup2(in_fd,0);
    dup2(out_fd,1);
    dup2(err_fd,2);

    close(in_fd);
    close(out_fd);
    close(err_fd);

    char buffer[1024];
    int bytes_read=0;
    
    while ((bytes_read = read(0, buffer, 1024)) > 0) {
        write(1, buffer, bytes_read);
        write(2, buffer, bytes_read);
    }

    dup2(stdout_original,1);
    close(stdout_original);

    write(1, "Final\n", 6);


    return 0;
}
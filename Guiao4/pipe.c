#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc,char* argv){
    int pipe_fd[2];
    pipe(pipe_fd);

    if (fork()==0){
        close(pipe_fd[1]); //read only
        int value=0;
        read(pipe_fd[0],&value,sizeof(int)); //nloqueia,enquanto existir possibilidade de ler dados,mas eles n forem lidos
        printf("%d\n",value);
        
        _exit(1);
    }
        close(pipe_fd[0]);
        int value=10;
        sleep(10);
        write(pipe_fd[1],&value,sizeof(int));
        wait(NULL);


    return 0;

}




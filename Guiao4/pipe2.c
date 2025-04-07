#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc,char* argv){
    int pipe_fd[2];
    pipe(pipe_fd);

    if (fork()==0){
        close(pipe_fd[1]); //read only
        int value=0;
        while(read(pipe_fd[0],&value,sizeof(int))>0){
            printf("%d\n",value);
        }
        close(pipe_fd[1]); 
        
        _exit(1);
    }
        close(pipe_fd[0]);
        int value=0;
        int i=0;
        while(i<100000){
            value=value+1;
            write(pipe_fd[1],&value,sizeof(int));
            i++;
        }
        close(pipe_fd[1]);
        wait(NULL);


    return 0;

}




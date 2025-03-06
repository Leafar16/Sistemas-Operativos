#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[]){
    int N=10;

    //loop 10x

    for (int i=0;i<N,i++){
        //create a child process
        int pid;
        if((pid=fork())==0){
            printf("Hello from child %d\n",i);

            _exit(0);
        }

        int status;

        wait(&status);

        if(WIFEXITED(status)){
            printf("Child %d exited with status %d\n",i,WEXITSTATUS(status));
        }
    }
    return 0;
}
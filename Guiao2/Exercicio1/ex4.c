#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[]){
    int N=10;
    int pid[N];
    //loop 10x

    for (int i=0;i<N,i++){
        //create a child process
        if((pid[i]=fork())==0){
            printf("Hello from child %d\n",i);

            _exit(i);
        }

    }
    for (int i=0;i<N,i++){
        int status;
        
        waitpid(pid[i],&status,0);

        if(WIFEXITED(status)){
            printf("Child %d exited with status %d\n",i,WEXITSTATUS(status));
        
    }
    }
 return 0;

}
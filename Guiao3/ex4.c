#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int my_system(int argc,char* argv[]){
    int N = argc;  

    if ((fork()) == 0) {  
        char* argumentos[N];
        for(int i=1;i<N;i++){
            argumentos[i-1]=argv[i];
        }
        argumentos[N-1]=NULL;
        execvp(argv[1], argumentos);
        _exit(1);  
    }

    int status;
    wait(&status);
   
}

int main(int argc,char* argv[]){
    int pid[argc];// para associar ao nome do programa
    for(int i=1;i<argc;i++){
        fork_ret=fork();
        if(fork_ret==0){ //EXECUTAR DENTRO
            my_system(argc,argv[i]);
            _exit(1)
        }else{
            pid[i]=fork_ret
        }
    }
    int status;
    wait(&status);
    if(status!=1)

}
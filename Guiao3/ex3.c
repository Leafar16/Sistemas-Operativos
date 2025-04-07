#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    
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

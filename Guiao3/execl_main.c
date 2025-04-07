#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv){
    printf("here\n");
    if(fork()==0){
        execlp("ls","ls","-l",NULL);//altera o que o processo está a fazer por completo
        _exit(1);
    }

    //        execlp("ls","ls","-l",NULL);//altera o que o processo está a fazer por completo


    printf("after exec\n");
}
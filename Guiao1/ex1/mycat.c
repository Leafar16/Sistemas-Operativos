#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */

int main(int argc,char *argv[]){


    char buf[20];
    int read_bytes;

    while((read_bytes=read(0,buf,20))>0){

    write(1,buf,read_bytes);//so escrever o que lemos


    }
    return 0;
}   
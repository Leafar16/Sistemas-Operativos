#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */

int main(int argc,char *argv[]){

int fopen=open(argv[1],O_CREAT | O_RDWR, 0666);
int fopen2=open(argv[2],O_CREAT |O_TRUNC | O_RDWR, 0666);


char buffer[10];
int read_bytes;
while((read_bytes=read(fopen,buffer,10))>0){

write(fopen2,buffer,read_bytes);
}
 close(fopen);
 close(fopen2);
return 0;
}
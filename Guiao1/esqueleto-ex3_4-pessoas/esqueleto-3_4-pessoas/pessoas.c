#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage:\n");
        printf("Add new person: ./pessoas -i [name] [age]\n");
        printf("List N persons: ./pessoas -l [N]\n");
        printf("Change person age: ./pessoas -u [name] [age]\n");
        printf("Change person age (v2): ./pessoas -o [position] [age]\n");
        return 1;
    }

    if (strcmp(argv[1], "-i") == 0) {
        int fd = open("pessoas.bin", O_CREAT | O_RDWR, 0666);
        if (fd < 0) {
            perror("Error opening file");
            return 1;
        }

        int age = atoi(argv[3]);
        Person* pessoa = person_create(argv[2], age);
        lseek(fd, 0, SEEK_END);
        write(fd, pessoa, sizeof(Person));
        
        close(fd);
        free(pessoa);
    }

    if (strcmp(argv[1], "-l") == 0) {
        char buffer[sizeof(Person)];
        int fopen = open("pessoas.bin", O_CREAT | O_RDWR, 0666); //O_APPEND
        
        for(int i=0;i<atoi(argv[2]);i++){
            int read_bytes = read(fopen, buffer, sizeof(Person));
            write(1, buffer, read_bytes);
            printf(" \n");
        }//spritnf+write
        close(fopen);
    }

    if (strcmp(argv[1], "-u") == 0) {
        printf("Not implemented yet\n");
    }

    if (strcmp(argv[1], "-o") == 0) {
        printf("Not implemented yet\n");
    }

    return 0;
}
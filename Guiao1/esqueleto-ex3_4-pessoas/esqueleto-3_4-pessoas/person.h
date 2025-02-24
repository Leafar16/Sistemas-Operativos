#ifndef PERSON_H
#define PERSON_H

typedef struct Perso{
    char name[100];
    int age;
} Person;

Person* person_create(char* name, int age);
#endif
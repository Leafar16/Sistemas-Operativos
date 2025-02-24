#include "person.h"
#include <stdlib.h>
#include <string.h>

Person* person_create(char* name, int age){
    Person* p = malloc(sizeof(Person));
    p->age = age;
    strcpy(p->name, name);
    return p;
}
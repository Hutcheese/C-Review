#include <stdio.h>

/* define the person struct here using the typedef syntax */
/*Typedefs allow us to define types with a different name - which can come in handy when dealing with structs and pointers.
In this case, we'd want to get rid of the long definition of a point structure. 
We can use the following syntax to remove the struct keyword from each time we want to define a new person:*/
typedef struct {
    char * name;
    int age;
} person;

int main() {
    person john;

    /* testing code */
    john.name = "John";
    john.age = 27;
    printf("%s is %d years old.", john.name, john.age);
}
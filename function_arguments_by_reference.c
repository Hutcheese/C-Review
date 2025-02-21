#include <stdio.h>

typedef struct {
  char * name;
  int age;
} person;

/* function declaration */
void birthday(person * p);

/* write your function here */
void birthday(person *p){
    p->age += 1; // This is the same as (*p).age += 1;
    // p->age++; // This is also valid
}

int main() {
  person john;
  john.name = "John";
  john.age = 27;

  printf("%s is %d years old.\n", john.name, john.age);
  birthday(&john);
  printf("Happy birthday! %s is now %d years old.\n", john.name, john.age);

  return 0;
}
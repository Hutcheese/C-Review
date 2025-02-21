#include <stdio.h>
#include <string.h>

// Define an enum to represent the type of value stored in the union
//
typedef enum {
    INT,
    FLOAT,
    STRING
} ValueType;

// Define a union that can hold an int, float, or string
// and a struct that contains the union and its type
typedef struct {
    ValueType type;
    union {
        int i;
        float f;
        char* s;
    } value;
} Number;

/**
 * Example program that demonstrates the use of unions in C.
 *
 * This program creates a single Number struct which has a
 * ValueType and a union of int, float and char*. It then
 * assigns different values to the Number struct and prints
 * them out.
 */
int main() {
    Number n;
    n.type = INT;
    n.value.i = 10;
    printf("Int value: %d\n", n.value.i);

    n.type = FLOAT;
    n.value.f = 3.14;
    printf("Float value: %f\n", n.value.f);

    n.type = STRING;
    n.value.s = strdup("hello");
    printf("String value: %s\n", n.value.s);
    free(n.value.s);
    return 0;
}
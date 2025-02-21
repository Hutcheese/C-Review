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
// A union is a special type of variable that can hold different types of data
// at different times. The union shares the same memory space for all its members,
// so the size of the union is the size of its largest member.
typedef struct {
    ValueType type;
    union {
        int i;  // integer member
        float f;  // floating-point member
        char* s;  // string member
    } value;
} Number;

// Define a new union type that can hold an array of integers or an array of characters
// This union is used to demonstrate how unions can be used to store binary data
union hiddenMessage {
    int  ints[6];  // integer array member
    char chars[21];  // character array member
};

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

    // Create an instance of the hiddenMessage union
    union hiddenMessage intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};

    // Access the character array member of the union
    // Note that the characters are stored in binary format, so we need to access them as characters
    printf("[");

    // only go to 18 because 1 byte is for the terminating 0 and we don't print the last in the loop
    for(int i = 0; i < 19; ++i)
        printf("%c, ", intCharacters.chars[i]);
    printf("%c]\n", intCharacters.chars[19]);
    printf("%s\n", intCharacters.chars);
}
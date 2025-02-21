#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf("Size of pointer (void*): %zu bytes\n", sizeof(void*));

    // Array and struct sizes
    int arr[10];
    printf("Size of int array with 10 elements: %zu bytes\n", sizeof(arr));

    struct Person {
        char name[20];
        int age;
    };
    printf("Size of Person struct with a name of 20 characters and an integer age: %zu bytes\n", sizeof(struct Person));

    // Struct with union example
    struct Data {
        int type;
        union {
            int int_val;
            float float_val;
            char char_val;
        } data;
    };
    printf("Size of Data struct with a int type and union(int, float, char): %zu bytes\n", sizeof(struct Data));

    // Why does this matter?

    // **Memory allocation**
    // When allocating memory on the heap using malloc(), you need to know the size of the data type you're allocating.
    int* ptr = (int*)malloc(sizeof(int));
    printf("Allocated %zu bytes for int pointer\n", sizeof(ptr));

    // **Data alignment**
    // Some data types have specific alignment requirements, which can affect the size of structs and arrays.
    // For example, on some platforms, int values must be aligned to 4-byte boundaries.
    struct AlignedStruct {
        char c;
        int i;
    };
    printf("Size of AlignedStruct: %zu bytes\n", sizeof(struct AlignedStruct));

    // **Network communication**
    // When sending data over a network, you need to know the size of the data types you're sending.
    // If you send data with the wrong size, the receiving end may interpret it incorrectly.
    int network_int = 0x12345678;
    printf("Sending int value over network: %zu bytes\n", sizeof(network_int));

    // **Embedded systems**
    // In embedded systems, memory is often limited, and knowing the size of data types is crucial for optimizing memory usage.
    struct EmbeddedStruct {
        char c;
        int i;
    };
    printf("Size of EmbeddedStruct: %zu bytes\n", sizeof(struct EmbeddedStruct));

    /*
    The reason EmbeddedStruct is 8 bytes instead of 5 bytes (1 byte for char + 4 bytes for int) is due to padding.
    In many computer architectures, data types need to be aligned to specific byte boundaries for efficient access.
    This is known as data alignment.
    */

    return 0;
}
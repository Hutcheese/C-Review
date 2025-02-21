#include <stdio.h>

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int factorial = 1;
    int i;

    /* Get array length*/
    size_t array_length = sizeof(array) / sizeof(array[0]);

    /* calculate the factorial using a for loop  here*/
    for (i = 0; i < array_length; i++) {
        factorial *= array[i];
    }

    printf("10! is %d.\n", factorial);
}
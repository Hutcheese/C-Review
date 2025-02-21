#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;

    // Printing the Array Elements and Addresses
    printf("\n=============================================\n");
    printf("Printing the Array Elements and Addresses\n");
    printf("---------------------------------------------\n");
    for(i = 0; i < 5; i++) {
        printf("intarray[%d] has value %d - and address @ %p\n", i, intarray[i], (void *)&intarray[i]);
    }

    // Incrementing a Pointer with (++)
    printf("\n=============================================\n");
    printf("Incrementing a Pointer with (++)\n");
    printf("---------------------------------------------\n");
    int *intpointer = &intarray[3]; //point to the 4th element in the array
    printf("address: %p - has value %d\n", (void *)intpointer, *intpointer); //print the address of the 4th element

    intpointer++; //now increase the pointer's address so it points to the 5th elemnt in the array
    printf("address: %p - has value %d\n\n\n", (void *)intpointer, *intpointer); //print the address of the 5th element

    // Printing the Array Elements and Addresses Again
    printf("\n=============================================\n");
    printf("Printing the Array Elements and Addresses Again\n");
    printf("---------------------------------------------\n");
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %p\n", i, intarray[i], (void *)&intarray[i]);

    // Decreasing a Pointer with (--)
    printf("\n=============================================\n");
    printf("Decreasing a Pointer with (--) \n");
    printf("---------------------------------------------\n");
    intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %p - has value %d\n", (void *)intpointer, *intpointer); //print the address of the 5th element

    intpointer--; //now decrease the point's address so it points to the 4th element in the array
    printf("address: %p - has value %d\n\n\n", (void *)intpointer, *intpointer); //print the address of the 4th element

    // Printing the Array Elements and Addresses Once More
    printf("\n=============================================\n");
    printf("Printing the Array Elements and Addresses Once More\n");
    printf("---------------------------------------------\n");
    for(i = 0; i < 5; i++)
    printf("intarray[%d] has value: %d - and address @ %p\n", i, intarray[i], (void *)&intarray[i]);

    // Adding Pointers with (+)
    printf("\n=============================================\n");
    printf("Adding Pointers with (+)\n");
    printf("---------------------------------------------\n");
    intpointer = &intarray[1]; //point to the 2nd element in the array
    printf("address: %p - has value %d\n", (void *)intpointer, *intpointer); //print the address of the 2nd element

    intpointer += 2; //now shift by two the point's address so it points to the 4th element in the array
    printf("address: %p - has value %d\n\n\n", (void *)intpointer, *intpointer); //print the address of the 4th element

    // Subtracting Pointers with (-)
    printf("\n=============================================\n");
    printf("Subtracting Pointers with (-)\n");
    printf("---------------------------------------------\n");
    intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %p - has value %d\n", (void *)intpointer, *intpointer); //print the address of the 5th element

    intpointer -= 2; //now shift by two the point's address so it points to the 3rd element in the array
    printf("address: %p - has value %d\n", (void *)intpointer, *intpointer); //print the address of the 3rd element

    // Exercise
    printf("\n=============================================\n");
    printf("Exercise\n");
    printf("---------------------------------------------\n");
    //-----------------------^
    int *pointer = &intarray[2];

    int *parray[3];

    for (i = 0; i < 3; i++) {
        parray[i] = pointer + i;
    }

    return 0;
}
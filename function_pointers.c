#include <stdio.h>
#include <stdlib.h> //for qsort()

/*
This is a comparison function in C, typically used as a callback for sorting algorithms like qsort().
It takes two void* pointers, casts them to int*, and returns the difference between the values they point to.
The result is used to determine the order of the elements being sorted.
In this case, it sorts in descending order.
*/
int compare(const void* left, const void* right)
{
    return (*(int*)right - *(int*)left);
    // go back to ref if this seems complicated: http://www.cplusplus.com/reference/cstdlib/qsort/
}

void f1(int var)
{
        printf("this is f1 and var is: %d\n", var);
}

void f2(int var)
{
        printf("this is f2 and var is: %d\n", var);
}

void f3(int var)
{
        printf("this is f3 and var is: %d\n", var);
}

main()
{
    // pointer to a function
    int (*cmp) (const void* , const void*);
    cmp = &compare; // assign the address of the function to the pointer

    int iarray[] = {1,2,3,4,5,6,7,8,9};

    /*
    qsort() is a standard library function in C that sorts an array.
    It takes four arguments:
    1. A pointer to the array to be sorted (iarray in this case).
        2. The number of elements in the array (sizeof(iarray)/sizeof(*iarray)).
            3. The size of each element in the array (sizeof(*iarray)).
                 4. A pointer to the comparison function (cmp) that defines the order of sorting.
    The comparison function should return a negative value if the first argument is less than the second,
    a positive value if the first argument is greater than the second, and zero if they are equal.
    In this case, the comparison function is used to sort the array in descending order.
    */
    qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp); 

    // Print the sorted array
    int c = 0;
    while (c < sizeof(iarray)/sizeof(*iarray))
    {
        printf("%d \t", iarray[c]);
        c++;
    }

    
    void (*pf[])(int) = {f1, f2, f3};

    printf("\nNow to call separate functions using function pointers\n");

    // Loop through the function pointers and call each function
    c = 0;
    while(c < 3)
    {
        pf[c](c);
        ++c;
    }
    
}
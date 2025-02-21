#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

int main() {
    point * mypoint = NULL;

    /* Dynamically allocate a new point
        struct which mypoint points to here */

    mypoint = (point *) malloc(sizeof(point));
    
    /* Check if the memory allocation was successful */
    if (mypoint == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit the program if memory allocation fails
    }

    /* Assign values to the point struct */
    /* Note: mypoint is a pointer to the struct,
        so we use -> to access the struct members */
    mypoint->x = 10;
    mypoint->y =5 ;
    printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);

    /* Free the allocated memory */
    /* Note: free() should be called only once for each
        malloc() call. Calling free() on a pointer that
        has already been freed results in undefined behavior */
    free(mypoint);
    return 0;
}
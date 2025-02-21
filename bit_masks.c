#include <stdio.h>
#include <assert.h>

/* Finish initializing the flags

This program uses bitwise operations to manipulate flags that represent different attributes of an object.
Each flag is represented by a single bit in a short integer.
The flags are defined using bitwise shifts, where each flag corresponds to a power of 2.
The program demonstrates how to set, clear, toggle, and check the status of these flags using bitwise operations
The final assertions check if the attributes are set correctly after the operations.
*/

const short FLAG_ON          = 1 << 0; // 1  (0x01)
const short FLAG_MOVEMENT    = 1 << 1; // 2  (0x02)
const short FLAG_TRANSPARENT = 1 << 2; // 4  (0x04)
const short FLAG_ALIVE       = 1 << 3; // 8  (0x08)
const short FLAG_BROKEN      = 1 << 4; // 16 (0x10)
const short FLAG_EDIBLE      = 1 << 5; // 32 (0x20)

int main() {
    short attributes = 0;

    /* Set the attributes ON, TRANSPARENT, and BROKEN */
    attributes |= FLAG_ON;
    attributes |= FLAG_TRANSPARENT;
    attributes |= FLAG_BROKEN;
    // possible solution(s):
    // attributes |= FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN;
    // attributes = FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN;

    printf("Attributes after setting ON, TRANSPARENT, and BROKEN: 0x%x\n", attributes);
    assert(attributes == (FLAG_ON | FLAG_TRANSPARENT | FLAG_BROKEN));

    /* Modify (set/clear/toggle) so the only attributes are ON and ALIVE */
    attributes &= ~FLAG_TRANSPARENT;
    // possible: attributes ^= FLAG_TRANSPARENT;
    attributes ^= FLAG_BROKEN;
    // possible: attributes &= ~FLAG_BROKEN;
    attributes |= FLAG_ALIVE;

    printf("Attributes after modifying to ON and ALIVE: 0x%x\n", attributes);
    assert(attributes == (FLAG_ON | FLAG_ALIVE));

    /* Check if the ALIVE flag is set */
    printf("Is ALIVE flag set? %s\n", (attributes & FLAG_ALIVE) ? "Yes" : "No");
    assert(attributes & FLAG_ALIVE);

    /* Check if the BROKEN flag is not set */
    printf("Is BROKEN flag set? %s\n", (attributes & FLAG_BROKEN) ? "Yes" : "No");

    /*
    Here are some examples of how this would be useful:

    Game development: In a game, you might have a character with various attributes such as "is alive", "is visible", "can move", etc.
        You can use bitwise operations to efficiently store and manipulate these attributes.
    Compression: Bitwise operations can be used to compress data by storing multiple values in a single byte or word.
    Cryptography: Bitwise operations are used extensively in cryptographic algorithms to perform encryption and decryption.
    Embedded systems: In embedded systems, bitwise operations can be used to optimize code and reduce memory usage.
    Database indexing: Bitwise operations can be used to create efficient indexes for databases.
    */

    return 0;assert(!(attributes & FLAG_BROKEN));
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Required for memset

// Define the structure for a node in the linked list
// We use 'node_t' as a typedef alias for 'struct node' to simplify declarations
typedef struct node {
    int val;              // The value stored in the node
    struct node * next;   // Pointer to the next node in the list
} node_t;

// Function to print all elements in the linked list
// Uses a single pointer (node_t * head) because it only reads the list, not modifying it
void print_list(node_t * head) {
    node_t * current = head; // Start from the head of the list

    while (current != NULL) { // Traverse until the end of the list
        printf("%d\n", current->val); // Print the value of the current node
        current = current->next; // Move to the next node
    }
}

// Function to remove the first node (head) of the linked list and return its value
// Uses a double pointer (node_t ** head) because it modifies the head pointer itself
int pop(node_t ** head) {
    int retval = -1; // Default return value in case the list is empty
    node_t * next_node = NULL;

    if (*head == NULL) { // If the list is empty, return -1
        return -1;
    }

    next_node = (*head)->next; // Store the second node in the list
    retval = (*head)->val; // Store the value of the head node before deleting it
    
    // SECURITY: Clear memory before freeing to prevent data leaks
    memset(*head, 0, sizeof(node_t));
    free(*head); // Free the memory of the head node
    *head = NULL; // SECURITY: Prevent dangling pointer

    *head = next_node; // Update the head to the next node

    return retval; // Return the removed value
}

// Function to remove a node with a specific value from the linked list
// Uses a double pointer (node_t ** head) since it may modify the head pointer
int remove_by_value(node_t ** head, int val) {
    node_t *previous, *current;

    if (*head == NULL) { // If the list is empty, return -1
        return -1;
    }

    // If the value is in the head node, use pop function to remove it
    if ((*head)->val == val) {
        return pop(head);
    }

    previous = *head; // Start from the head
    current = (*head)->next; // Start checking from the second node
    
    while (current) { // Traverse through the list
        if (current->val == val) { // If we find the value
            previous->next = current->next; // Remove the node from the list
            
            // SECURITY: Clear memory before freeing to prevent data leaks
            memset(current, 0, sizeof(node_t));
            free(current); // Free the memory of the removed node
            current = NULL; // SECURITY: Prevent dangling pointer
            
            return val; // Return the removed value
        }

        previous = current; // Move forward in the list
        current  = current->next; // Move to the next node
    }
    return -1; // Return -1 if value is not found
}

// Function to delete the entire linked list and free memory
// Uses a single pointer (node_t *head) because it does not modify the head itself
void delete_list(node_t *head) {
    node_t  *current = head, 
            *next = head;

    while (current) { // Traverse through the list
        next = current->next; // Store the next node
        
        // SECURITY: Clear memory before freeing to prevent data leaks
        memset(current, 0, sizeof(node_t));
        free(current); // Free the current node
        current = NULL; // SECURITY: Prevent dangling pointer

        current = next; // Move to the next node
    }
    // SECURITY: Ensure dangling pointer is cleared
    head = NULL;
}

int main() {
    // Manually creating a linked list with values 1 -> 2 -> 3 -> 4
    node_t * test_list = (node_t *) malloc(sizeof(node_t)); // Allocate memory for the head node
    if (!test_list) return 1; // SECURITY: Check if malloc fails
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    if (!test_list->next) { free(test_list); return 1; } // SECURITY: Prevent memory leak
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    if (!test_list->next->next) { free(test_list->next); free(test_list); return 1; } // SECURITY: Prevent memory leak
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    if (!test_list->next->next->next) { free(test_list->next->next); free(test_list->next); free(test_list); return 1; } // SECURITY: Prevent memory leak
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL; // Last node points to NULL

    // Remove node with value 3 from the linked list
    remove_by_value(&test_list, 3);

    // Print the updated linked list
    print_list(test_list);

    // SECURITY: Ensure memory is freed at the end
    delete_list(test_list);
    test_list = NULL; // Clear dangling pointer

    return 0;
}

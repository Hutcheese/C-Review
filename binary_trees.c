#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the ordered binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to perform pre-order traversal (DFS)
void preOrderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function to perform in-order traversal (DFS)
void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Function to perform post-order traversal (DFS)
void postOrderTraversal(Node* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to perform level-order traversal (BFS)
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;
    int level = 0;
    Node** queue = (Node**) malloc(sizeof(Node*) * 10);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left) {
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }
    free(queue);
}

int main() {
    Node* root = NULL;
    root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);
    root->right->right->right = createNode(10);

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Level-order traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
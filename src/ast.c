#include "ast.h"
#include <stdio.h> // For perror

// Function to create a new node
Node* createNode(int type, const char* value, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));  // Allocate memory for the node
    if (!node) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE); // Exit the program if allocation fails
    }
    node->type = type;
    strcpy(node->value, value);  // Copy the value to the node
    node->left = left;
    node->right = right;
    return node;
}

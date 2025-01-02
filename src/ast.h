#ifndef AST_H
#define AST_H

#include <stdlib.h>  // For malloc
#include <string.h>  // For strcpy

// Define the Node structure
typedef struct Node {
    int type;               // Node type (e.g., operator, operand)
    char value[50];         // Node value
    struct Node* left;      // Left child
    struct Node* right;     // Right child
} Node;

// Function to create a new node
Node* createNode(int type, const char* value, Node* left, Node* right);

#endif // AST_H

#include "codegen.h"
#include "ast.h"
#include <stdio.h> // For printf

// Define constants for node types
#define ASSIGNMENT 1
#define ADDITION 2

void generateAssembly(Node* node) {
    if (!node) return;

    if (node->type == ASSIGNMENT) {
        printf("LOAD %s\n", node->right->value);
        printf("STORE %s\n", node->left->value);
    } else if (node->type == ADDITION) {
        generateAssembly(node->left);
        generateAssembly(node->right);
        printf("ADD\n");
    }
}

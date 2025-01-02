#include "lexer.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

// Function to parse statements
ASTNode* parseStatement(Token* token) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (node == NULL) {
        printf("Error: Memory allocation failed in parseStatement\n");
        exit(EXIT_FAILURE);
    }
    node->value = "int statement";  // Placeholder
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to print AST (pre-order traversal)
void printAST(ASTNode* node) {
    if (node == NULL) return;
    printf("Node: %s\n", node->value);
    printAST(node->left);
    printAST(node->right);
}

// Main parser function
ASTNode* parseProgram(FILE *file) {
    Token token;
    ASTNode* root = NULL;
    token = getNextToken(file);  // Get the first token
    while (token.type != TOKEN_EOF) {
        printf("Processing token of type: %d\n", token.type);
        if (token.type == TOKEN_INT) {
            root = parseStatement(&token);
        }
        token = getNextToken(file);  // Get the next token
    }
    return root;
}

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// Define the node structure for the AST
typedef struct ASTNode {
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

// Function declarations
ASTNode* parseStatement(Token* token);
void printAST(ASTNode* node);
ASTNode* parseProgram(FILE *file);

#endif // PARSER_H

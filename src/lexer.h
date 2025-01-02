#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

// Define the token types
typedef enum {
    TOKEN_INT, TOKEN_IDENTIFIER, TOKEN_NUMBER, TOKEN_ASSIGN,
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_IF, TOKEN_EQUAL, TOKEN_LBRACE, TOKEN_RBRACE,
    TOKEN_SEMICOLON, TOKEN_UNKNOWN, TOKEN_EOF
} TokenType;

// Define the structure of a token
typedef struct {
    TokenType type;
    char text[256];
} Token;

// Function declarations
Token getNextToken(FILE *file);

#endif // LEXER_H

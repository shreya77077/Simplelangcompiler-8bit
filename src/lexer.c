#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LEN 100

// Define token types
typedef enum {
    TOKEN_INT, TOKEN_IDENTIFIER, TOKEN_NUMBER, TOKEN_ASSIGN,
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_IF, TOKEN_EQUAL, TOKEN_LBRACE, TOKEN_RBRACE,
    TOKEN_SEMICOLON, TOKEN_UNKNOWN, TOKEN_EOF
} TokenType;

// Structure for holding a token
typedef struct {
    TokenType type;
    char text[MAX_TOKEN_LEN];
} Token;

// Function to get the next token from the input file
Token getNextToken(FILE *file) {
    Token token;
    int c;

    while ((c = fgetc(file)) != EOF) {
        // Skip whitespace characters
        if (isspace(c)) continue;

        // Handle alphabetic characters (keywords or identifiers)
        if (isalpha(c)) {
            int len = 0;
            token.text[len++] = c;

            while (isalnum(c = fgetc(file))) {
                if (len < MAX_TOKEN_LEN - 1) token.text[len++] = c;
            }
            ungetc(c, file);
            token.text[len] = '\0';

            if (strcmp(token.text, "int") == 0) {
                token.type = TOKEN_INT;
            } else if (strcmp(token.text, "if") == 0) {
                token.type = TOKEN_IF;
            } else {
                token.type = TOKEN_IDENTIFIER;
            }
            return token;
        }

        // Handle numeric literals
        if (isdigit(c)) {
            int len = 0;
            token.text[len++] = c;

            while (isdigit(c = fgetc(file))) {
                if (len < MAX_TOKEN_LEN - 1) token.text[len++] = c;
            }
            ungetc(c, file);
            token.text[len] = '\0';
            token.type = TOKEN_NUMBER;
            return token;
        }

        // Handle special characters like '=', '+', '-', etc.
        switch (c) {
            case '=': token.type = TOKEN_ASSIGN; token.text[0] = '='; token.text[1] = '\0'; return token;
            case '+': token.type = TOKEN_PLUS; token.text[0] = '+'; token.text[1] = '\0'; return token;
            case '-': token.type = TOKEN_MINUS; token.text[0] = '-'; token.text[1] = '\0'; return token;
            case '{': token.type = TOKEN_LBRACE; token.text[0] = '{'; token.text[1] = '\0'; return token;
            case '}': token.type = TOKEN_RBRACE; token.text[0] = '}'; token.text[1] = '\0'; return token;
            case ';': token.type = TOKEN_SEMICOLON; token.text[0] = ';'; token.text[1] = '\0'; return token;
            default: 
                token.type = TOKEN_UNKNOWN; 
                token.text[0] = c; 
                token.text[1] = '\0'; 
                printf("Warning: Unknown character '%c'\n", c); 
                return token;
        }
    }

    token.type = TOKEN_EOF;
    token.text[0] = '\0';
    return token;
}

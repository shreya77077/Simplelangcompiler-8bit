#include <stdio.h>
#include "src/lexer.h"   // Include lexer.h for the lexer functions
#include "src/parser.h"  // Include parser.h for parser functions
 #include "src/codegen.h" // Include codegen.h if you need code generation functions

int main() {
    FILE *file = fopen("input.txt", "r"); // Open the input file
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    // Parse the program
    // ASTNode* ast = parseProgram(file);
    ASTNode* ast = parseProgram(file);
    if (ast == NULL) {
        printf("Error: Parsing failed. AST is NULL\n");
        fclose(file);
        return 1;
    }

    // Print or process the AST as needed
    printAST(ast);

    fclose(file); // Don't forget to close the file
    return 0;
}

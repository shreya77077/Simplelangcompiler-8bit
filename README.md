# SimpleLang Compiler Documentation

## 1. Introduction

### 1.1 Project Overview

The SimpleLang Compiler is a simple programming language compiler that translates SimpleLang code into assembly code.

### 1.2 Features

- Lexical analysis
- Syntax parsing
- Code generation
- Basic constructs (variable assignment, arithmetic operations, loops, conditionals)

## 2. System Design and Architecture

### 2.1 Compiler Components

- Lexer
- Parser
- Code Generator
- Error Handler

### 2.2 Data Structures

```c
typedef struct {
    TokenType type;
    char* value;
} Token;
```

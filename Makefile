# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Source and object files
SRC_FILES = $(SRC_DIR)/ast.c $(SRC_DIR)/codegen.c $(SRC_DIR)/lexer.c $(SRC_DIR)/parser.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES)) main.o

# Target executable
TARGET = compiler

# Default rule
all: $(TARGET)

# Linking the target executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling main.c separately (since it's in the root directory)
main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compiling each source file in the src directory
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning up build files
clean:
	rm -f $(OBJ_FILES) $(TARGET)

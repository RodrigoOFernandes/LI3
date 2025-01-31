# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -pedantic -Ofast -Werror=ignored-qualifiers -g `pkg-config --cflags glib-2.0`
LDFLAGS = `pkg-config --libs glib-2.0` -lm
# Executables
EXEC = programa-principal
EXEC_TEST = programa-testes
EXEC_INTERACT = programa-interativo
# Directories
SRC_DIR = src
INCLUDE_DIR = include
RESULT_DIR = resultados
# Dynamically find source files excluding main files
COMMON_SRC_FILES = $(filter-out $(SRC_DIR)/main.c $(SRC_DIR)/testes.c $(SRC_DIR)/programainterativo.c, $(shell find $(SRC_DIR) -name "*.c"))
COMMON_OBJ_FILES = $(COMMON_SRC_FILES:.c=.o)

# Object files for specific executables
MAIN_OBJ = $(SRC_DIR)/main.o
TEST_OBJ = $(SRC_DIR)/testes.o
INTERACT_OBJ = $(SRC_DIR)/programainterativo.o

# Default target to build all executables
all: $(EXEC) $(EXEC_TEST) $(EXEC_INTERACT)

# Build programa-principal
$(EXEC): $(COMMON_OBJ_FILES) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Build programa-testes
$(EXEC_TEST): $(COMMON_OBJ_FILES) $(TEST_OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Build programa-interativo
$(EXEC_INTERACT): $(COMMON_OBJ_FILES) $(INTERACT_OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

# Generic rule to compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Run programa-principal
run: $(EXEC)
	./$(EXEC) arg1

# Clean up build artifacts
clean:
	rm -f $(EXEC) $(EXEC_TEST) $(EXEC_INTERACT) $(COMMON_OBJ_FILES) $(MAIN_OBJ) $(TEST_OBJ) $(INTERACT_OBJ) $(RESULT_DIR)/*

# Phony targets
.PHONY: all clean run

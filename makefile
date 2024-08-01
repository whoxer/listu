# Diretórios
OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -I$(SRC_DIR)

# Arquivo binário
TARGET = $(BIN_DIR)/tasks

# Lista de arquivos fontes e objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Regra padrão
all: $(TARGET)

# Linkagem do programa
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compilação dos arquivos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Regra de phony para evitar conflitos com arquivos reais
.PHONY: all clean

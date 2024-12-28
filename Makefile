# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = 

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test

TARGET = $(BIN_DIR)/listu
TEST_TARGET = $(BIN_DIR)/test_listu

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_SRCS))

# Regras
.PHONY: all clean run test install

all: $(TARGET)

# Compilação do programa principal
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# Regra para compilar os arquivos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Programa de teste
test: $(TEST_TARGET)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Executar o programa principal
run: $(TARGET)
	./$(TARGET)

# Instalação do programa
install: $(TARGET)
	@echo "Instalando $(TARGET) em /usr/local/bin..."
	@mkdir -p /usr/local/bin
	@cp $(TARGET) /usr/local/bin/
	@chmod +x /usr/local/bin/$(notdir $(TARGET))
	@echo "Instalação concluída. O programa pode ser executado com '$(notdir $(TARGET))'."

# Instruções de Compilação e Execução
#
# Compilação
#   Windows: mingw32-make
#   Linux:   make
#
# Execução com arquivo de teste
#   Windows: mingw32-make run-win
#   Linux:   make run-linux
#
# Limpeza dos arquivos (.o e executável)
#   Windows: mingw32-make clean-win
#   Linux:   make clean-linux

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Iheaders -g

# Diretórios
SRC_DIR = sources
OBJ_DIR = $(SRC_DIR)
BIN = main

# Arquivos fonte e objetos
SRCS = main.c \
	$(SRC_DIR)/treinador.c \
	$(SRC_DIR)/pokemon.c \
	$(SRC_DIR)/centroDePesquisa.c \
	$(SRC_DIR)/pokelista.c \
	$(SRC_DIR)/coordenada.c \
	$(SRC_DIR)/controleDaMissao.c

OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(BIN)

# Linkagem final
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

# Compilação dos .c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# --- Windows ---
run-win: $(BIN)
	$(BIN) testes\teste1.txt

clean-win:
	del /s /q *.o $(BIN) $(BIN).exe 2>nul
	
# --- Linux ---
run-linux: $(BIN)
	./$(BIN) testes/teste1.txt

clean-linux:
	rm -f $(OBJS) $(BIN)
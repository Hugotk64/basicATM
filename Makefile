# Compilador
CC = gcc

# Directorios
SRC_DIR = src
INC_DIR = headers
BIN = passwordManager

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Flags
CFLAGS = -Wall -I$(INC_DIR)

# Regla por defecto
all: $(BIN)

# Compilación del ejecutable
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para compilar archivos .c a .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/%.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Limpiar archivos generados
clean:
	rm -f $(SRC_DIR)/*.o $(BIN)

# Recompilar desde cero
rebuild: clean all

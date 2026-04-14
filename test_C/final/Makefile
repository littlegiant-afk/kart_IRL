# Compilateur
CC = gcc

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Nom de l'exécutable
TARGET = $(BIN_DIR)/main

# Flags de compilation
CFLAGS = -Wall -pedantic -I$(INC_DIR)

# Librairies
LDFLAGS = -lwiringPi

# Récupère tous les .c dans src
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Transforme src/xxx.c en obj/xxx.o
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compilation des .o dans obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR) $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage : supprime .o + exécutable
clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(TARGET)

.PHONY: all clean

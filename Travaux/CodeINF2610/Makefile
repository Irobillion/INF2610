# Nom de l'exécutable à générer
TARGET = processus

# Compilateur à utiliser
CC = gcc

# Options de compilation
CFLAGS = -g -Wall

# Fichiers source
SOURCES = $(wildcard *.c)

# Fichiers objet générés après la compilation
OBJECTS = $(SOURCES:.c=.o)

# Cible par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Règle pour générer les fichiers objet
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cible pour nettoyer les fichiers générés
clean:
	rm -f $(OBJECTS) $(TARGET)

# Cible pour exécuter le programme
.PHONY: run
run: $(TARGET)
	./$(TARGET)

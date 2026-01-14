# =============================================================================
# Makefile - Projet BigBinary ESIEA S5
# =============================================================================

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = bigbinary
SRCDIR = src
OBJDIR = obj

# Fichiers sources et objets
SRCS = main.c $(SRCDIR)/BigBinary.c
OBJS = $(OBJDIR)/main.o $(OBJDIR)/BigBinary.o

# Règle par défaut
all: $(OBJDIR) $(TARGET)

# Création du répertoire obj
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compilation de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des fichiers objets
$(OBJDIR)/main.o: main.c $(SRCDIR)/BigBinary.h
	$(CC) $(CFLAGS) -c main.c -o $@

$(OBJDIR)/BigBinary.o: $(SRCDIR)/BigBinary.c $(SRCDIR)/BigBinary.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/BigBinary.c -o $@

# Nettoyage
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Recompilation complète
rebuild: clean all

# Exécution
run: $(TARGET)
	./$(TARGET)

# Aide
help:
	@echo "Commandes disponibles:"
	@echo "  make        - Compile le projet"
	@echo "  make run    - Compile et execute"
	@echo "  make clean  - Supprime les fichiers compiles"
	@echo "  make rebuild - Nettoie et recompile"

.PHONY: all clean rebuild run help

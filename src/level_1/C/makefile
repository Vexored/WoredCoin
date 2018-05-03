# Specific part of the Makefile
# EXEC contient le nom des exécutables à générer, le nom est indépendant des noms de fichiers auquels le makefile fait appel
EXEC = main
# Begin generic part of the Makefile
# CC indique le compilateur utilisé
CC=gcc
# CFLAGS regroupe les options de compilation (par exemple "-Werror" transforme les Warning en Error, ne produit pas d'exécutable)
CFLAGS=-std=c99 -Wextra -Wall -pedantic
# LDFLAGS regroupe les options de l'édition de liens
LDFLAGS=

# SRC contient la liste des fichiers sources et OBJ contient la liste des fichiers objets
SRC= $(wildcard *.c)
OBJ= $(SRC:.c =.o)

ifeq ($(DEBUG), yes)
	CFLAGS += -g
	LDFLAGS =
else
	CFLAGS += -O3 -DNDEBUG
	LDFLAGS =
endif

all : $(EXEC)

$(EXEC): block.o blockchain.o transaction.o merkle.o main.o
	$(CC) -o main block.o blockchain.o transaction.o merkle.o main.o $(LDFLAGS)

block.o: block.c
	$(CC) -o block.o -c block.c $(CFLAGS)

blockchain.o: blockchain.c
	$(CC) -o blockchain.o -c blockchain.c $(CFLAGS)

transaction.o: transaction.c
	$(CC) -o transaction.o -c transaction.c $(CFLAGS)

merkle.o: merkel.c
	$(CC) -o merkel.o -c merkel.c $(CFLAGS)

main.o: main.c block.h blockchain.h transaction.h merkel.h
	$(CC) -o main.o -c main.c $(CFLAGS)

# On utilise .PHONY au cas où clean ou mrproper soient également des nom de fichiers présents dans le répertoire
.PHONY: clean mrproper

# Permet de supprimer tous les fichiers intermédiaires
clean:
	@rm -rf *.o

#Permet de supprimer tout ce qui a été généré par le makefile
mrproper: clean
	@rm -rf $(EXEC)
# End generic part of the makefile

# List of target dependencies
main.o: block.h blockchain.h transaction.h merkle.h

# variables à modifier pour personaliser
# la compilation
CPP=gcc
CXXFLAGS=
LDFLAGS=
EXEC=main
SRC= $(wildcard *.c)
HEADERS= $(wildcard *.h)
OBJ= $(SRC:.cpp=.o)
# à mettre à vide si on veut paramétrer
# les dépendances pour chaque source
DEPENDENCY_FOR_ALL= $(HEADERS)

# d'autres cibles peuvent être rajoutées
all: $(EXEC)

# génération de l'exécutable
$(EXEC): $(OBJ)
	$(CPP) -o $@ $^ $(LDFLAGS)

# génération des fichiers .o
%.o: %.c $(DEPENDENCY_FOR_ALL)
	$(CPP) -o $@ -c $< $(CXXFLAGS)

# il est possible de paramétrer les
# dépendances pour chaque fichier source
# si DEPENDENCY_FOR_ALL est vide

#quelques actions de base
.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

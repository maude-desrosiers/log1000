# the compiler to use
CC = g++

CXX_FLAGS	:= -Wall -Wextra -std=c++11 -g

INCLUDE	:= include
LIB	:= lib
LIBRARIES	:=


# Fichier exécutable produit
EXEC=typerabais
EXECUTABLETESTS	= exemple_test

# Répertoire contenant les fichiers source
SOURCE=src
TESTS=test
# Répertoire contenant les fichiers compilés
BINAIRE=bin

# Répertoire contenant les données utilisées par le logiciel
DONNEES=data

# Nom du fichier contenant les données
CLIENTS=clients.dat

# =======================
# Compilation du logiciel
# =======================

# commande par défaut, construit un exécutable appelé $(EXEC) et le lance.
# l'exécutable est appelé avec ./$(EXEC) nomfichierdonnees.dat
all: $(BINAIRE)/$(EXEC)
	./$(BINAIRE)/$(EXEC) $(DONNEES)/$(CLIENTS)

# Fait le "linking" entre les fichiers objets pour produire l'exécutable
$(BINAIRE)/$(EXEC): $(BINAIRE)/main.o $(BINAIRE)/client.o $(BINAIRE)/rabais.o $(BINAIRE)/facture.o $(BINAIRE)/afficheur.o
	$(CC) $(CXX_FLAGS) -o $@ $^ 

# Compile le "main" pour produire le fichier objet.
$(BINAIRE)/main.o: $(SOURCE)/main.cpp $(SOURCE)/rabais.h $(SOURCE)/facture.h
	mkdir -p $(BINAIRE)
	$(CC) $(CXX_FLAGS) -o $@ -c $<

# Compile la classe Client pour produire le fichier objet.
$(BINAIRE)/client.o: $(SOURCE)/client.cpp $(SOURCE)/client.h
	$(CC) $(CXX_FLAGS) -o $@ -c $<

# Compile la classe Rabais pour produire le fichier objet.
$(BINAIRE)/rabais.o: $(SOURCE)/rabais.cpp $(SOURCE)/rabais.h $(SOURCE)/client.h $(SOURCE)/facture.h
	$(CC) $(CXX_FLAGS) -o $@ -c $<

# Compile la classe Facture pour produire le fichier objet.
$(BINAIRE)/facture.o: $(SOURCE)/facture.cpp $(SOURCE)/facture.h
	$(CC) $(CXX_FLAGS) -o $@ -c $<

# Conmpile la classe Afficheur pour produire le fichier objet.
$(BINAIRE)/afficheur.o: $(SOURCE)/afficheur.cpp $(SOURCE)/afficheur.h $(SOURCE)/rabais.h $(SOURCE)/facture.h
	 $(CC) $(CXX_FLAGS) -o $@ -c $<

# ===========
# Utilitaires
# ===========


# Enlève l'exécutable et les fichiers objets intermédiaires.
clean:
	#rm -rf $(BINAIRE)/$(EXEC) $(BINAIRE)/*.o
	rm -rf $(BINAIRE)/*.o
	rm -rf $(BINAIRE)/$(EXEC)
	rm -rf $(TESTS)/$(BINAIRE)/*.o
	rm -rf $(TESTS)/$(BINAIRE)/$(EXECUTABLETEST)


#---------------------test--------------------#
test: $(TESTS)/$(BINAIRE)/$(EXECUTABLETESTS)
	./$(TESTS)/$(BINAIRE)/$(EXECUTABLETESTS) 

$(TESTS)/$(BINAIRE)/$(EXECUTABLETESTS): $(TESTS)/$(BINAIRE)/main.o $(TESTS)/$(BINAIRE)/RabaisTest.o $(SOURCE)/rabais.o $(SOURCE)/client.o $(SOURCE)/facture.o 
	$(CC) $(CXX_FLAGS) -o $@ $^ -lcppunit 

$(TESTS)/$(BINAIRE)/main.o: $(TESTS)/$(SOURCE)/main.cpp $(TESTS)/$(SOURCE)/RabaisTest.h
	mkdir -p $(TESTS)/$(BINAIRE)
	$(CC) $(CXX_FLAGS) -o $@ -c $<

$(TESTS)/$(BINAIRE)/RabaisTest.o: $(TESTS)/$(SOURCE)/RabaisTest.cpp $(TESTS)/$(SOURCE)/RabaisTest.h #$(SOURCE)/rabais.h
	$(CC) $(CXX_FLAGS) -o $@ -c $<





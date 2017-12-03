CC = g++ --std=c++11
CFLAGS = -g -Wall
EXEC_NAME = main
INCLUDES =
LIBS =
OBJ_FILES = main.o lieux.o transaction.o transaction_debutant.o nom.o joueur.o joueur_debutant.o
FILES = main.cc lieux.cc transaction.cc transaction_debutant.cc nom.cc joueur.cc joueur_debutant.hh
INSTALL_DIR =

all : $(EXEC_NAME) 

clean :
	rm -rf $(EXEC_NAME) $(OBJ_FILES)
	rm -rf *~ *# .depends
	reset

$(EXEC_NAME) : $(OBJ_FILES) $(FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)

.depends : 
	$(CC) -MM $(FILES) > .depends

-include .depends

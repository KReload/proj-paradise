CC = g++ --std=c++11
CFLAGS = -g -Wall
EXEC_NAME = main
INCLUDES =
LIBS =
OBJ_FILES = main.o event_surprise.o lieux.o transaction.o transaction_debutant.o nom.o joueur.o joueur_debutant.o joueur_medium.o joueur_expert.o transaction_medium.o transaction_fake.o message.o transaction_expert.o
FILES = main.cc event_surprise.cc lieux.cc transaction.cc transaction_debutant.cc nom.cc joueur.cc joueur_debutant.cc joueur_medium.cc joueur_expert.cc transaction_medium.cc transaction_fake.cc message.cc transaction_expert.cc
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

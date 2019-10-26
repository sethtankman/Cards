
CC = g++
CFLAGS = -Wall -std=c++11


LIBSM = .

magic: libSM.a magic.o
	$(CC) $(CFLAGS) -o magic magic.o DeckList.o Deck.o -L$(LIBSM)/ -lSM

libSM.a: DeckList.o Deck.o Matchup.o
	ar -rcs libSM.a DeckList.o Deck.o Matchup.o

Deck.o : Deck.h Deck.cpp
	$(CC) $(CFLAGS) -c -I$(LIBSM) Deck.cpp

DeckList.o : DeckList.h DeckList.cpp
	$(CC) $(CFLAGS) -c -I$(LIBSM) DeckList.cpp

Matchup.o : Matchup.h Matchup.cpp
	$(CC) $(CFLAGS) -c -I$(LIBSM) Matchup.cpp

magic.o : magic.cpp DeckList.h Deck.h
	$(CC) $(CFLAGS) -c -I$(LIBSM) magic.cpp

clean:
	rm magic *.o libSM.a

test:
	./magic

game: utility.o player.o dealer.o carddeck.o game.o
	g++ utility.o player.o dealer.o carddeck.o game.o -o game

game.o: game.cpp dealer.h player.h utility.h carddeck.h
	g++ -c game.cpp

carddeck.o: carddeck.cpp carddeck.h
	g++ -c carddeck.cpp

dealer.o: dealer.cpp dealer.h carddeck.h player.h utility.h
	g++ -c dealer.cpp

player.o: player.cpp player.h carddeck.h
	g++ -c player.cpp

utility.o: utility.cpp utility.h
	g++ -c utility.cpp

clean:
	rm -f *.o game

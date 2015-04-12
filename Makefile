all: game

tile.o: tile.cpp tile.h
	g++ tile.cpp -c

game: game.cpp tile.o
	g++ game.cpp tile.o -o game

clean:
	rm tile.o game

all: game

tile.o: tile.cpp tile.h
	g++ tile.cpp -c

board.o: board.cpp board.h
	g++ board.cpp -c

game: game.cpp tile.o board.o
	g++ game.cpp tile.o board.o -o game

clean:
	rm tile.o game

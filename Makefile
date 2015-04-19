all: game

tile.o: tile.cpp tile.h
	g++ tile.cpp -c

labyrinth.o: labyrinth.cpp labyrinth.h
	g++ labyrinth.cpp -c

board.o: board.cpp board.h
	g++ board.cpp -c

character.o: character.cpp character.h
	g++ character.cpp -c

game: game.cpp tile.o labyrinth.o board.o character.o
	g++ game.cpp tile.o labyrinth.o board.o character.o -o game

clean:
	rm tile.o labyrinth.o board.o character.o game

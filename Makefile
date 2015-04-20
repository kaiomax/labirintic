all: game

tile.o: tile.cpp tile.h
	g++ tile.cpp -c

board.o: board.cpp board.h
	g++ board.cpp -c

character.o: character.cpp character.h
	g++ character.cpp -c

maze.o: maze.cpp maze.h
	g++ maze.cpp -c

game: game.cpp tile.o board.o maze.o character.o
	g++ game.cpp tile.o board.o maze.o character.o -o game -lallegro -lallegro_primitives

clean:
	rm tile.o board.o maze.o character.o game

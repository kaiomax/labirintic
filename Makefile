all: game

game: game.cpp
	g++ game.cpp -o game

clean:
	rm game
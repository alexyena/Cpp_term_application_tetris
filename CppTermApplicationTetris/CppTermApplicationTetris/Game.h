#pragma once
#include <chrono>
#include <thread>
#include <conio.h>
//#include "SDL.h"

#include "Queue.h"
#include "Board.h"
#include "ActivePolymino.h"

#define START_DELAY 250

class Game
{
	Board board;
	Queue queue;
	ActivePolymino active;
	int score;

public:
	Game();

	void placeOnBoard();
	void movePolymino(char direction);
	void leaveOnBoard();
	void runPolymino();

	bool isNextBeyongBottom();
	bool isCellOnBorderLine(int i, int j);
	bool isCellOnBorderLineForShapeCoordinates(int i, int j, int coord_row, int coord_col);

	bool isCollision(int i, int j);
	bool outOfBorders();

	void show();

	~Game();
};


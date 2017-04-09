#include "Game.h"



Game::Game()
{
}

void Game::placeOnBoard()
{
	active.clear();
	active = queue.front();
	active.setCoordinates(0, B_WIDTH / 2 - 3);
	queue.update_queue();
}



bool Game::isCollision(int i, int j)
{
	bool result = false;
	for (auto x = 0; x < SHAPE_ROWS; x++)
	{
		for (auto y = 0; y < SHAPE_COLS; y++)
		{
			if (isCellOnBorderLineForShapeCoordinates(x, y, i, j) == true && i - 4 + x > 0 && j + y > 0 && j + y < B_WIDTH)
			{
				if (board.getBoardPieceByCoordinate(i - 4 + x, j + y) == true && active.getShapePiece(x, y) == true)
				{
					return true;
				}
			}
		}
	}
	return result;
}

bool Game::outOfBorders()
{
	bool result = false;

	for (auto i = 0; i < SHAPE_ROWS; i++)
	{
		for (auto j = 0; j < SHAPE_COLS; j++)
		{
			if (active.getShapePiece(i, j) == true && isCellOnBorderLine(i, j) == false)
			{
				return true;
			}
		}
	}
	return result;
}

void Game::movePolymino(char direction)
{
	switch (direction)
	{
	case 'f': {
		if (isCollision(active.nextRow(), active.currCol()) == true || isNextBeyongBottom() == true) { throw - 2; }
	}	break;
	case 'r': {
		if (isCollision(active.currRow(), active.nextCol()) == true || outOfBorders() == true) { throw - 1; }
	}	break;
	case 'l': {
		if (isCollision(active.currRow(), active.prevCol()) == true || outOfBorders() == true) { throw - 1; }
	}	break;
	}
	active.move(direction);

}

void Game::leaveOnBoard()
{
	for (auto i = 0; i <= active.lastShapeLine(); i++)
	{
		for (auto j = 0; j < SHAPE_COLS; j++)
		{
			if (active.getShapePiece(i, j) == true && isCellOnBorderLine(i, j) == true)
			{
				board.setBoardPieceByCoordinate(active.currRow() - SHAPE_ROWS + 1 + i, active.currCol() + j, true);
			}
		}
	}
}

void Game::runPolymino()
{
	using namespace std::chrono_literals;
	int key_pressed, score = 0, event_score;
	board.clear();

	while (board.isLastLineEmpty() == true)
	{
		if (active.isActive() == false) { placeOnBoard(); }
		else active.clear();

		while (active.isActive() == true)
		{
			try { movePolymino('f'); }
			catch (int e)
			{
				if (e == -2)
				{
					leaveOnBoard();
					event_score = board.deleteFullLines();
					score += 10 * event_score * event_score;
				}
				active.clear();
			}


			if (_kbhit())
			{
				key_pressed = _getch();

				if (key_pressed == 224)
				{
					switch (_getch())
					{
					case 77:
					{
						try { movePolymino('r'); }
						catch (int e)
						{
							if (e == -1) { break; }
						}
					}	break;
					case 75:
					{
						try { movePolymino('l'); }
						catch (int e)
						{
							if (e == -1) { break; }
						}
					}	break;
					case 80:
					{
						while (active.isActive())
						{
							try { movePolymino('f'); }
							catch (int e)
							{
								if (e == -2)
								{
									leaveOnBoard();
									event_score = board.deleteFullLines();
									score += 10 * event_score * event_score;
								}
								active.clear();
							}
						}
					}	break;
					}
				}
				else 
				{
					switch (key_pressed)
					{
					case 32: {active.Rotate(); }	break;
					}
				}
			}
			/*--------------------------------------------------------------------------------------*/

			system("cls");
			for (auto i = 0; i < B_DEPTH; i++)
			{
				for (auto j = 0; j < B_WIDTH; j++)
				{
					if (board.getBoardPieceByCoordinate(i, j) == true || active.getShapePieceByCoordinate(i, j) == true)
					{
						std::cout << '#';
					}
					else { std::cout << '.'; }
				}

				std::cout << std::endl;
			}
			std::cout << std::endl;

			/*--------------------------------------------------------------------------------------*/

			std::this_thread::sleep_for(250ms);
		}
	}

//	std::cout << "Game over!";
}

bool Game::isNextBeyongBottom()
{
	int tmp = active.currLastShapeLineRow() + 1;
	if (tmp < B_DEPTH) { return false; }
	else { return true; }
}

bool Game::isCellOnBorderLine(int i, int j)
{
	return isCellOnBorderLineForShapeCoordinates(i, j, active.currRow(), active.currCol());
}
bool Game::isCellOnBorderLineForShapeCoordinates(int i, int j, int coord_row, int coord_col)	// i = coordinates[0], coordinates[1] of active polymino
{
	if ((coord_row - SHAPE_ROWS + i + 1 >= B_DEPTH) || (coord_col + i < 0) || (coord_col + i >= B_WIDTH))
	{
		return false;
	}
	else
	{
		return true;
	}
}


void Game::show()
{
	runPolymino();
	system("pause");
}

Game::~Game()
{
}

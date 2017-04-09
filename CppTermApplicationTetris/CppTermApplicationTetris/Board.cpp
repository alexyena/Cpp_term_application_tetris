#include "Board.h"



Board::Board()
{
	for (int i = 0; i < B_DEPTH; i++)
	{
		board[i].reset();
	}
}

void Board::setBoardPieceByCoordinate(int i, int j, bool value)
{
	board[i][j] = value;
}

bool Board::getBoardPieceByCoordinate(int i, int j)
{
	if (i < 0 || i >= B_DEPTH || j < 0 || j >= B_WIDTH)
	{
		throw - 1;
	}
	return board[i][j];
}

bool Board::isLastLineEmpty()
{
	return (board[0].none());
}

void Board::deleteLine(int line)
{
	for (auto i = line; i > 0; i--)
	{
		board[i] = board[i - 1];
	}
	board[0].reset();
}

void Board::unifyUncollidedLines(int line)
{
	bool isLinesCollision = false;
	int lineUp0, lineDown0, lines;

	if ((board[line] & board[line + 1]).none() == true)
	{
		lineUp0 = line + 1;
		lineDown0 = line;
		lines = 1;
	}
	else
	{
		lineUp0 = lineDown0 = line;
		isLinesCollision = true;
		lines = 0;
	}

	while (isLinesCollision == false)
	{
		for (auto i = 0; i < lines + 1; i++)
		{
			if ((board[lineUp0 + i] & board[lineDown0 - 1 + i]).none() == false)
			{
				isLinesCollision = true;
			}
			else
			{
				lines++;
				lineDown0--;
			}
		}
	}

	if (lines > 0)
	{
		for (auto i = 0; i < lines; i++)
		{
			board[lineDown0 + i] = (board[lineDown0 + i] | board[lineUp0 + i]);
		}

		lineUp0 = line + lines;
		for (auto i = lineUp0; i > 0; i--)
		{
			board[i - lines] = board[i];
		}
		for (auto i = 0; i < lines; i++)
		{
			board[i].reset();
		}
	}
}

int Board::deleteFullLines()
{
	int count = 0, first_line;

	for (auto i = 19; i >= 0; i--)
	{
		if (board[i].all() == true)
		{
			if (count == 0) { first_line = i; }
			while (board[i].all() == true)
			{
				deleteLine(i);
				count++;
			}
		}
	}
	return count;
}

bool Board::isLineFull(int row_id)
{
	return (board[row_id].all());
}

void Board::ClearLine(int row_id)
{
	for (auto i = row_id; i > 0; i++)
	{
		board[row_id] = board[row_id - 1];
	}
	board[0].reset();
}

void Board::clear()
{
	for (int i = 0; i < B_DEPTH; i++)
	{
		board[i].reset();
	}
}

Board::~Board()
{
}

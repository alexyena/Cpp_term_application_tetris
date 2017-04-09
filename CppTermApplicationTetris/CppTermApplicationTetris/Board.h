#pragma once
#include <bitset>
#include <iostream>

#define B_WIDTH 10
#define B_DEPTH 20


class Board
{
	std::bitset<B_WIDTH> board[B_DEPTH];
public:
	Board();

	void setBoardPieceByCoordinate(int i, int j, bool value);
	bool getBoardPieceByCoordinate(int i, int j);
	bool isLineFull(int row_id);
	bool isLastLineEmpty();

	void deleteLine(int line);
	void unifyUncollidedLines(int line);
	int	 deleteFullLines();

	void ClearLine(int row_id);
	void clear();

	~Board();
};


#include "ActivePolymino.h"



ActivePolymino & ActivePolymino::operator=(Polymino & const obj)
{
	this->clear();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			this->shape[i][j] = obj.returnShapeFilled(i, j);
		}
	}
	Active = true;
	return *this;
}

void ActivePolymino::setCoordinates(const int i, const int j)
{
	coordinates[0] = i;
	coordinates[1] = j;
}

int ActivePolymino::isActive()
{
	return Active;
}

int ActivePolymino::currRow()
{
	return coordinates[0];
}

int ActivePolymino::currLastShapeLineRow()
{
	return coordinates[0] - (SHAPE_ROWS - 1 - lastShapeLine());
}

int ActivePolymino::currCol()
{
	return coordinates[1];
}

int ActivePolymino::nextRow()
{
	return coordinates[0] + 1;
}

int ActivePolymino::nextCol()
{
	return coordinates[1] + 1;
}

int ActivePolymino::prevCol()
{
	return coordinates[1] - 1;
}

bool ActivePolymino::getShapePieceByCoordinate(int i, int j)
{
	int row = i - coordinates[0] + SHAPE_ROWS - 1;
	int col = j - coordinates[1];

	if (row >= 0 && row < SHAPE_ROWS && col >= 0 && col < SHAPE_COLS)
	{
		return shape[row][col];
	}
	else
	{
		return false;
	}
}

bool ActivePolymino::getShapePiece(const int i, const int j)
{
	return shape[i][j];
}


void ActivePolymino::move(const char direction)
{
	switch (direction)
	{
	case 'f': {
		coordinates[0]++;
	}	break;
	case 'r': {
		coordinates[1]++;
	}	break;
	case 'l': {
		coordinates[1]--;
	}	break;
	}
}

void ActivePolymino::clear()
{
	type = 0;

	for (auto i = 0; i < SHAPE_ROWS; i++)
	{
		shape[i].reset();
	}

	rotation = 0;

	coordinates[0] = NULL;
	coordinates[1] = NULL;
	Active = false;
}



ActivePolymino::~ActivePolymino()
{
}

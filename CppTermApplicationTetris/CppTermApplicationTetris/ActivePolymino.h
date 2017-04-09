#pragma once
#include "Polymino.h"

class ActivePolymino : public Polymino
{
	int coordinates[2];
	bool Active;

public:
	ActivePolymino() :Polymino()
	{
		coordinates[0] = NULL;
		coordinates[1] = NULL;
		Active = false;
	};

	ActivePolymino& operator = (Polymino& const obj);

	void setCoordinates(const int i, const int j);

	int isActive();
	int currRow();
	int currLastShapeLineRow();
	int currCol();
	int nextRow();
	int nextCol();
	int prevCol();

	bool getShapePieceByCoordinate(const int i, const int j);
	bool getShapePiece(const int i, const int j);

	void move(const char direction);
	void clear();

	~ActivePolymino();
};


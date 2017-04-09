#pragma once
#include <bitset>
#include <iostream>

#define TYPES_QTY 8
#define SHAPE_COLS 5
#define SHAPE_ROWS 5

class Polymino
{
protected:
	std::bitset<SHAPE_COLS>shape[SHAPE_ROWS];
	int type;
	int rotation;
public:
	Polymino();
	Polymino(int type, int rotation);

	Polymino& operator = (Polymino& obj);
	virtual void Rotate();

	bool returnShapeFilled(int i, int j);
	int lastShapeLine();

//	void show() const;

	~Polymino();
};


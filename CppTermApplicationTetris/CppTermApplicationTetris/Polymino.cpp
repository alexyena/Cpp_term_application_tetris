#include "Polymino.h"



Polymino::Polymino()
{
	type = 0;

	for (int i = 0; i < SHAPE_ROWS; i++)
	{
		for (int j = 0; j < SHAPE_COLS; j++)
		{
			shape[i][j] = 0;
		}
	}
}

Polymino::Polymino(int _type, int rotation)
{
	type = _type;

	for (int i = 0; i < SHAPE_ROWS; i++)
	{
		for (int j = 0; j < SHAPE_COLS; j++)
		{
			shape[i][j] = 0;
		}
	}

	switch (type)
	{
	case 1: //-- ----------------L-Shape
	{
		shape[1][2] = 1;		//00000
		shape[2][2] = 1;		//00100
		shape[3][2] = 1;		//00100
		shape[3][3] = 1;		//00110
	}	break;					//00000
	case 2: //-- ----------------T-Shape
	{
		shape[1][1] = 1;		//00000
		shape[1][2] = 1;		//01110
		shape[1][3] = 1;		//00100
		shape[2][2] = 1;		//00100
		shape[3][2] = 1;		//00000
	}	break;
	case 3: //-- ----------------Short T-Shape
	{
		shape[2][1] = 1;		//00000
		shape[2][2] = 1;		//00000
		shape[2][3] = 1;		//01110
		shape[3][2] = 1;		//00100
	}	break;					//00000
	case 4: //-- ----------------Left Forward
	{
		shape[1][2] = 1;		//00000
		shape[2][2] = 1;		//00100
		shape[2][3] = 1;		//00110
		shape[3][3] = 1;		//00010
	}	break;					//00000
	case 5: //-- ----------------Right Forward
	{
		shape[1][3] = 1;		//00000
		shape[2][3] = 1;		//00010
		shape[3][2] = 1;		//00110
		shape[3][3] = 1;		//00100
	}	break;					//00000
	case 6: //-- ----------------U - shape
	{
		shape[1][1] = 1;		//00000
		shape[1][3] = 1;		//01010
		shape[2][1] = 1;		//01010
		shape[2][3] = 1;		//01110
		shape[3][1] = 1;		//00000
		shape[3][2] = 1;
		shape[3][3] = 1;
	}	break;
	case 7: //-- ----------------Small U-Shape
	{
		shape[1][1] = 1;		//00000
		shape[1][3] = 1;		//01010
		shape[2][1] = 1;		//01010	
		shape[2][2] = 1;		//01110
		shape[2][3] = 1;		//00000
	}	break;
	case 8: //-- ----------------Strait line
	{
		shape[0][2] = 1;		//00100
		shape[1][2] = 1;		//00100
		shape[2][2] = 1;		//00100	
		shape[3][2] = 1;		//00100
								//00000
	}	break;

	}

	for (auto i = 0; i < rotation; i++)
	{
		Rotate();
	}
}

Polymino & Polymino::operator=(Polymino & obj)
{
	for (auto i = 0; i < SHAPE_ROWS; i++)
	{
		for (auto j = 0; j < SHAPE_COLS; j++)
		{
			shape[i][j] = obj.shape[i][j];
		}
	}
	type = obj.type;
	rotation = obj.rotation;
	return *this;
}

bool Polymino::returnShapeFilled(int i, int j)
{
	return shape[i][j];
}

int Polymino::lastShapeLine()
{
	int tmp;
	for (auto i = 0; i < SHAPE_ROWS; i++)
	{
		if (shape[i].any() == true) { tmp = i; }
	}

	return tmp;
}

void Polymino::Rotate()
{
	bool tmp;
	for (int i = 0; i < SHAPE_ROWS; i++)
	{
		for (int j = i + 1; j < SHAPE_COLS; j++)
		{
			if (shape[i][j] != shape[j][i])
			{
				tmp = shape[i][j];
				shape[i][j] = shape[j][i];
				shape[j][i] = tmp;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		std::swap(shape[i], shape[4 - i]);
	}

	if (rotation == 3) { rotation = 0; }
	else { rotation++; }
}
/*
void Polymino::show() const
{
for (auto i = 0; i < SHAPE_ROWS; i++)
{
for (auto j = 0; j < SHAPE_COLS; j++)
{
if (shape[i][j] == 0)
{
std::cout << '.';
}
else
{
std::cout << '#';
}
}
std::cout << std::endl;
}
std::cout << std::endl << std::endl;
}
*/



Polymino::~Polymino()
{
}

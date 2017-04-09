#include "Queue.h"



Queue::Queue()
{
	srand(time(0));
	for (auto i = 0; i < 3; i++)
	{
		upcoming_polimino.push(Polymino(rand() % TYPES_QTY + 1, rand() % 4));
	}
}


Polymino Queue::front()
{
	return upcoming_polimino.front();
}

void Queue::update_queue()
{
	srand(time(0));
	upcoming_polimino.pop();
	upcoming_polimino.push(Polymino(rand() % TYPES_QTY + 1, rand() % 4));
}
/*
void Queue::show()
{
	while (upcoming_polimino.size() > 0)
	{
		upcoming_polimino.front().show();
		upcoming_polimino.pop();
	}
}
*/
Queue::~Queue()
{
}

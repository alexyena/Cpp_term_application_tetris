#pragma once
#include <queue>
#include "Polymino.h"
#include "time.h"

class Queue
{
	std::queue<Polymino> upcoming_polimino;
public:
	Queue();

	Polymino front();
	void update_queue();

//	void show();
	~Queue();
};

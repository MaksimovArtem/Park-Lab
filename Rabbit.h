#ifndef RABBIT_H
#define RABBIT_H

#include "Animal.h"

class Rabbit :
	public Animal
{
public:
	Rabbit(int animal_lifetime, int x, int y, int animal_reproduction_ready_time);
	//functions
	void live() override;
	~Rabbit();
};


#endif // !RABBIT_H



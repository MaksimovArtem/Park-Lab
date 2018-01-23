#ifndef RABBIT_H
#define RABBIT_H

#include "Animal.h"
class Rabbit :
	public Animal
{
public:
	Rabbit();

	//functions
	void live() override;
	void move() override;//think about move function in Animal

	~Rabbit();
};


#endif // !RABBIT_H



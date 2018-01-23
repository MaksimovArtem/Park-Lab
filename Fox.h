#ifndef FOX_H
#define FOX_H

#include "Animal.h"

class Fox :
	public Animal
{
public:
	Fox();

	//functions
	void live() override;
	void move() override;//think about move function in Animal

	~Fox();
};

#endif // !FOX_H
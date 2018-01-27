#ifndef FOX_H
#define FOX_H

#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(int animal_lifetime, int x, int y, int animal_reproduction_ready_time);
	//functions
	void live() override;
	~Fox();
};

#endif // !FOX_H
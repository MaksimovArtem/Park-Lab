#ifndef GRASS_H
#define GRASS_H

#include "Object.h"

class Grass :
	public Object
{
public:
	Grass();

	//functions
	void live() override;
	~Grass();
};


#endif // !GRASS_H


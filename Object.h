#ifndef  OBJECT_H
#define OBJECT_H

#include "Park.h" //each Object must know about Park 

class Object
{
public:
	//functions
	virtual void live() = 0;
};

#endif // ! OBJECT_H



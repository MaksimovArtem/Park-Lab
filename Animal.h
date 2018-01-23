#ifndef ANIMAL_H
#define ANIMAL_H

#include "Object.h"
class Animal :
	public Object
{
private:
	int hunger;//is it really int value?
public:
	Animal();
	
	//getters
	int get_hunger();

	//setters
	void set_hunger(int value);

	//functions
	virtual void live() = 0;
	virtual void move() = 0;// we can descript this function here with parametr of view 1/2 for rab/fox accordingly
	~Animal();
};

#endif// !ANIMAL_H
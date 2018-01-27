#ifndef ANIMAL_H
#define ANIMAL_H

#include "Object.h"

const int animal_lifetime = 10;
const int animal_reproduction_ready_time = 0;

class Animal : 
	public Object
{	
protected:
	int age;
	int x_coord;
	int y_coord;
	int time_since_the_last_reproduction;
	int hunger;
public:
	Animal(int animal_lifetime, int x, int y, int animal_reproduction_ready_time);
	
	//getters
	
	int get_hunger();
	int get_age();
	int get_x_coord();
	int get_y_coord();
	int get_time_since_the_last_reproduction();
	

	//setters
	//void set_hunger(int value);

	//functions
	virtual void live() = 0;
	void move(int animal);// 1/2 for rabbit/foxes
	~Animal();
};

#endif// !ANIMAL_H
#include "Animal.h"



Animal::Animal(int animal_lifetime, int x, int y, int animal_reproduction_ready_time): age(animal_lifetime), x_coord(x),y_coord(y), time_since_the_last_reproduction(animal_reproduction_ready_time)
{
}

int Animal::get_hunger()
{
	return hunger;
}

int Animal::get_age()
{
	return age;
}

int Animal::get_x_coord()
{
	return x_coord;
}

int Animal::get_y_coord()
{
	return y_coord;
}

int Animal::get_time_since_the_last_reproduction()
{
	return time_since_the_last_reproduction;
}

void Animal::move(int animal)
{
	//some move func
}

Animal::~Animal()
{
}

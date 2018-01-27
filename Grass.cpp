#include "Grass.h"



Grass::Grass(int grass_lifetime, int x, int y, int grass_reproduction_ready_time):age(grass_lifetime), x_coord(x), y_coord(y),time_since_the_last_reproduction(grass_reproduction_ready_time)
{
}

int Grass::get_age()
{
	return age;
}

int Grass::get_x_coord()
{
	return x_coord;
}

int Grass::get_y_coord()
{
	return y_coord;
}

int Grass::get_time_since_the_last_reproduction()
{
	return time_since_the_last_reproduction;
}

void Grass::live()
{
	//some live
}

Grass::~Grass()
{
}

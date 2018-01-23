#include "Object.h"

Object::Object()//:age(0), x_coord(-1), y_coord(-1), time_since_the_last_reproduction(0)//-1 because it must be useless after creation and must gget some sense after the setters
//we don't create any objects of Object. Initialization is useless
{
}

//getters
int Object::get_age()
{
	return age;
}

int Object::get_x_coord()
{
	return x_coord;
}

int Object::get_y_coord()
{
	return y_coord;
}

int Object::get_time_since_the_last_reproduction()
{
	return time_since_the_last_reproduction;
}

//setters
void Object::set_age(int value)
{
	age = value;
}

void Object::set_x_coord(int value)
{
	x_coord = value;
}

void Object::set_y_coord(int value)
{
	y_coord = value;
}

void Object::set_time_since_the_last_reproduction(int value)
{
	time_since_the_last_reproduction = value;
}

//functions

void Object::kill_an_object()
{
	//some murder
}
Object::~Object()
{
}

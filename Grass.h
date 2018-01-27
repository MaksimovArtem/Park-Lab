#ifndef GRASS_H
#define GRASS_H

#include "Object.h"
extern int grass_lifetime = 10;
extern int grass_reproduction_ready_time = 0;
class Grass :
	public Object
{
private:
	int age;
	int x_coord;
	int y_coord;
	int time_since_the_last_reproduction;
public:
	Grass(int grass_lifetime, int x, int y, int grass_reproduction_ready_time);

	int get_age();
	int get_x_coord();
	int get_y_coord();
	int get_time_since_the_last_reproduction();
	//functions

	void live() override;
	~Grass();
};


#endif // !GRASS_H


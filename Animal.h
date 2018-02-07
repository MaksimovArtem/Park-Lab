#ifndef ANIMAL_H
#define ANIMAL_H

#include "Object.h"

class Animal : public Object {
public:
	virtual int get_hunger() = 0;
	virtual int get_age() = 0;
	virtual int get_x_coord() = 0;
	virtual int get_y_coord() = 0;
	virtual void set_x_coord(int a) = 0;
	virtual void set_y_coord(int b) = 0;
	virtual int get_time_since_the_last_reproduction() = 0;

	virtual Object* live(int **field) = 0;

	virtual ~Animal() {};
};

#endif
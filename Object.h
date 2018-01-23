#ifndef  OBJECT_H
#define OBJECT_H

#include "Park.h" //each Object must know about Park 

class Object
{
private:
	int age;
	int x_coord;
	int y_coord;
	int time_since_the_last_reproduction;
public:
	Object();

	//getters
	int get_age();
	int get_x_coord();
	int get_y_coord();
	int get_time_since_the_last_reproduction();

	//setters
	void set_age(int value);
	void set_x_coord(int value);
	void set_y_coord(int value);
	void set_time_since_the_last_reproduction(int value);

	//functions
	virtual void live()=0;
	void kill_an_object();//we have to use template here i suppose

	~Object();
};

#endif // ! OBJECT_H



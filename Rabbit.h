#ifndef RABBIT_H
#define RABBIT_H

#include "Animal.h"

class Rabbit : public Animal {
private:
	int age;
	int x_coord;
	int y_coord;
	int time_since_the_last_reproduction;
	int hunger;
public:

	Rabbit(int x, int y);

	int get_hunger() override;
	int get_age() override;
	int get_x_coord() override;
	int get_y_coord() override;
	void set_x_coord(int a) override {x_coord = a;};
	void set_y_coord(int b) override {y_coord = b;};
	int get_time_since_the_last_reproduction() override;

	Object* live(int **field) override;
	virtual ~Rabbit();
};

#endif



#ifndef PARK_H
#define PARK_H

#include <vector>
#include "Object.h"
#include "Animal.h"
#include "Grass.h"
#include "Rabbit.h"
#include "Fox.h"

class Park {
private:
	int **field;

	std::vector<Object*> obj_list;

public:
	void Print_park();
	void generate_park();
	void exist();
};

#endif


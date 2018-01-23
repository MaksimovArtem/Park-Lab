#ifndef PARK_H
#define PARK_H

#include "Object.h" //because this class rules

#include "Grass.h"
#include "Rabbit.h"
#include "Fox.h"

#include <vector>

class Park
{
private:
	int field[20][20];//matrix
	std::vector<Grass*> grass_list;
	std::vector<Rabbit*> rabbit_list;
	std::vector<Fox*> fox_list;

public:
	Park();

	void changeMatrix(int start_x,int start_y,int start_value, int end_x,int end_y, int end_value);//we have to overload this func?!
	~Park();
};




#endif // !PARK_H


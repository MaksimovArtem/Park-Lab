#include "Park.h"



Park::Park()
{
}

void Park::changeMatrix(int start_x, int start_y, int start_value, int end_x, int end_y, int end_value)
{
	field[start_x][start_y] = start_value;
	field[end_x][end_y] = end_value;
}

Park::~Park()
{
}

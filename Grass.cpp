#include "Grass.h"
#include <cstdlib>

using namespace std;

Grass::Grass(int x, int y): age(0), x_coord(x), y_coord(y), time_since_the_last_reproduction(0) {};

int Grass::get_age() {
	return age;
};

int Grass::get_x_coord() {
	return x_coord;
};

int Grass::get_y_coord() {
	return y_coord;
};

int Grass::get_time_since_the_last_reproduction() {
	return time_since_the_last_reproduction;
};

Object* Grass::live(int **field) {
	age ++;
	time_since_the_last_reproduction ++;

	if (age >= grass_max_age)
		return this;


	if (time_since_the_last_reproduction >= grass_reprod_time) {

		int a = 2 * (rand() % 2) - 1;
		int b = rand() % 3;
		int c = rand() % 3;

		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) {

				int new_x = x_coord + dx3[(3 + b + i * a) % 3];
				int new_y = y_coord + dy3[(3 + c + j * a) % 3];

				if ((new_x < N) && (new_x >= 0) && (new_y < N) && (new_y >= 0) && (field[new_x][new_y] == 0)) {

					Object *newgrass = new Grass(new_x, new_y);
					time_since_the_last_reproduction = 0;
					return newgrass;
				}
			}
	}

	return nullptr;
}

Grass::~Grass() {}

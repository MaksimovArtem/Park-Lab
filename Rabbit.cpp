#include "Rabbit.h"
#include <cstdlib>

using namespace std;

Rabbit::Rabbit(int x, int y): age(0), x_coord(x), y_coord(y), time_since_the_last_reproduction(0), hunger(0) {};

int Rabbit::get_hunger() {
	return hunger;
};

int Rabbit::get_age() {
	return age;
};

int Rabbit::get_x_coord() {
	return x_coord;
};

int Rabbit::get_y_coord() {
	return y_coord;
};

int Rabbit::get_time_since_the_last_reproduction() {
	return time_since_the_last_reproduction;
};

Object* Rabbit::live(int **field) {
	age ++;
	hunger++;
	time_since_the_last_reproduction ++;

	if (age >= rab_max_age || hunger >= rab_max_hunger)
		return this;

	int a = 2 * (rand() % 2) - 1;
	int b = rand() % 5;
	int c = rand() % 5;
	int new_x = 0;
	int new_y = 0;

	if (time_since_the_last_reproduction >= rab_reprod_time) {

		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j) {

				new_x = x_coord + dx5[(5 + b + i * a) % 5];
				new_y = y_coord + dy5[(5 + c + j * a) % 5];

				if ((new_x < N) && (new_x >= 0) && (new_y < N) && (new_y >= 0) && (field[new_x][new_y] == 0)) {

					time_since_the_last_reproduction = 0;

					Object *newrab = new Rabbit(new_x, new_y);
					return newrab;
				}
			}
	}

	if (hunger >= rab_crit_hunger) {

		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j) {

				new_x = x_coord + dx5[(5 + b + i * a) % 5];
				new_y = y_coord + dy5[(5 + c + j * a) % 5];

				if ((new_x < N) && (new_x >= 0) && (new_y < N) && (new_y >= 0) && (field[new_x][new_y] == 1)) {

					hunger -= rab_crit_hunger;

					Object *victim = new Grass(new_x, new_y);

					return victim;////dead grass
				}
			}
	}

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j) {

			new_x = x_coord + dx5[(5 + b + i * a) % 5];
			new_y = y_coord + dy5[(5 + c + j * a) % 5];

			if ((new_x < N) && (new_x >= 0) && (new_y < N) && (new_y >= 0) && (field[new_x][new_y] == 0)) {

				Object *newrab = new Rabbit(new_x, new_y);
				return newrab;
			}
		}


	return nullptr;
}

Rabbit::~Rabbit() {}

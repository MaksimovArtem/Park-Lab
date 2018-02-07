#include "Fox.h"
#include <cstdlib>

using namespace std;

Fox::Fox(int x, int y): age(0), x_coord(x), y_coord(y), time_since_the_last_reproduction(0), hunger(0) {};

int Fox::get_hunger() {
	return hunger;
};

int Fox::get_age() {
	return age;
};

int Fox::get_x_coord() {
	return x_coord;
};

int Fox::get_y_coord() {
	return y_coord;
};

int Fox::get_time_since_the_last_reproduction() {
	return time_since_the_last_reproduction;
};

Object* Fox::live(int **field) {
	age ++;
	hunger++;
	time_since_the_last_reproduction ++;

	if (age >= fox_max_age || hunger >= fox_max_hunger)
		return this;

	int a = 2 * (rand() % 2) - 1;
	int b = rand() % 9;
	int c = rand() % 9;
	int new_x = 0;
	int new_y = 0;

	if (time_since_the_last_reproduction >= fox_reprod_time) {
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {

				new_x = x_coord + dx9[(9 + b + i * a) % 9];
				new_y = y_coord + dy9[(9 + c + j * a) % 9];

				if ((new_x < N) && (new_x >= 0) && (new_y < N) && (new_y >= 0) && (field[new_x][new_y] == 0)) {

					time_since_the_last_reproduction = 0;

					Object *newfox = new Fox(new_x, new_y);
					return newfox;
				}
			}
	}
	////eating grass//////////
	if (hunger >= fox_crit_hunger) {

		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {

				new_x = x_coord + dx9[(9 + b + i * a) % 9];
				new_y = y_coord + dy9[(9 + c + j * a) % 9];

				if ((new_x < N) && (new_x >= 0) && (new_y < N) && (new_y >= 0) && (field[new_x][new_y] == 2)) {

					hunger -= fox_crit_hunger;

					Object *victim = new Rabbit(new_x, new_y);

					return victim;////dead rabbit
				}
			}
	}
	///////////////////////

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {

			new_x = x_coord + dx9[(9 + b + i * a) % 9];
			new_y = y_coord + dy9[(9 + c + j * a) % 9];

			if ((new_x < N) && (new_x >= 0) && (new_y < N) && (new_y >= 0) && (field[new_x][new_y] == 0)) {

				Object *newfox = new Fox(new_x, new_y);
				return newfox;
			}
		}


	return nullptr;
}

Fox::~Fox() {}

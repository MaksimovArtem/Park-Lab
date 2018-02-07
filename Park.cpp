#include "Park.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

void Park::generate_park() {
	srand(time(0));

	field = new int*[N];

	for (int i = 0; i < N; ++i) {
		field[i] = new int [N];
		for (int j = 0; j < N; ++j) {
			int num = rand() % (N * N);
			if (num < fox_chance_to_appear) {
				field[i][j] = 3;
				Fox *newfox = new Fox(i, j);
				obj_list.push_back(newfox);
			}
			else if (num < rab_chance_to_appear) {
				field[i][j] = 2;
				Rabbit *newrab = new Rabbit(i, j);
				obj_list.push_back(newrab);
			}
			else if (num < grass_chance_to_appear) {
				field[i][j] = 1;
				Grass *newgrass = new Grass(i, j);
				obj_list.push_back(newgrass);
			}
			else
				field[i][j] = 0;
		}
	}
	return;
};

void Park::Print_park() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			if (field[i][j] == 1)
				//cout <<  "* ";
				cout << "\e[42m\e[30m" << field[i][j] << "\e[0m" << ' ';
			else if (field[i][j] == 2)
				//cout <<  "@ ";
				cout << "\e[47m\e[30m" << field[i][j] << "\e[0m" << ' ';
			else if (field[i][j] == 3)
				//cout <<  "# ";
				cout << "\e[41m" << field[i][j] << "\e[0m" << ' ';
			else
				//cout <<  ". ";
				cout << field[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
};

void Park::exist() {
	int k = 0;

	while (obj_list.size() > 0 && k < 300) {

		k++;

		// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
		cout << "\x1B[2J\x1B[H";

		cout << "Iter: " << k << " Vec size: " << obj_list.size() << endl << endl;

		Print_park();

		vector <Object*> children;
		vector <int> deadman;
		int counter = -1;

		for (auto& i : obj_list) {
			counter++;

			if (i != nullptr) {///////////object exists in vector(still alive)

				Object* newobj = i->live(field);

				if (newobj != nullptr) {////else nothing happens

					int current_x = i->get_x_coord();
					int current_y = i->get_y_coord();
					int future_x = newobj->get_x_coord();
					int future_y = newobj->get_y_coord();

					if (newobj == i) { /////////////dying object

						field[current_x][current_y] = 0;
						i = nullptr;//////////will die after loop
						deadman.push_back(counter);

					} else {///child/moving or meal

						if (field[future_x][future_y] == 0) {////child/moving

							if (field[current_x][current_y] == 1)
								field[future_x][future_y] = 1;
							else if (field[current_x][current_y] == 2)
								field[future_x][future_y] = 2;
							else
								field[future_x][future_y] = 3;

							if (i->get_time_since_the_last_reproduction() == 0) /////////child
								children.push_back(newobj);

							else {///moving

								field[current_x][current_y] = 0;////old place

								i->set_x_coord(future_x);
								i->set_y_coord(future_y);

								delete newobj;
							}
						}

						else {///eating

							if (field[current_x][current_y] == 2)
								field[future_x][future_y] = 2;
							else
								field[future_x][future_y] = 3;

							field[current_x][current_y] = 0;///old place

							int counter_ = -1;

							bool flag = false;

							for (auto& gg : obj_list) {/////seeking for victim
								counter_++;
								if (gg != nullptr && gg->get_x_coord() == future_x && gg->get_y_coord() == future_y) {
									gg = nullptr;
									deadman.push_back(counter_);
									flag = true;
									break;
								}
							}

							counter_ = -1;

							if (!flag) {
								for (auto& gg : children) {/////seeking for victim
									counter_++;
									if (gg != nullptr && gg->get_x_coord() == future_x && gg->get_y_coord() == future_y) {
										delete children[counter_];
										children.erase(children.begin() + counter_);
										break;
									}
								}
							}

							i->set_x_coord(future_x);
							i->set_y_coord(future_y);

							delete newobj;
						}
					}
				}
			}
		}

		int counter3 = 0;

		sort(deadman.begin(), deadman.begin() + deadman.size());

		for (auto& i : deadman) {//////////////deleting deadmans
			delete obj_list[i - counter3];
			obj_list.erase(obj_list.begin() + i - counter3);
			counter3++;
		}

		for (auto& i : children)////pushing new objects
			obj_list.push_back(i);


		children.clear();
		deadman.clear();
	}

	cout << "SYSTEM IS DEAD!" << endl;

	for (auto& i : obj_list)////deleting
		delete i;

	obj_list.clear();

	for (int i = 0; i < N; ++i)
		delete [] field[i];
	delete [] field;


};


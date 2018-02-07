#include <iostream>
#include "Park.cpp"
#include "Grass.cpp"
#include "Rabbit.cpp"
#include "Fox.cpp"

using namespace std;

int main()
{
	Park mypark;

	while (true) {
		mypark.generate_park();
		mypark.exist();
	}

	return 0;
}
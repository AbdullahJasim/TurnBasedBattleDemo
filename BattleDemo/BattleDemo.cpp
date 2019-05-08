#include <iostream>

#include "Unit.h"

using namespace std;

int main() {
	Unit unit1 = Unit("Herja", 40, 40);
	Unit unit2 = Unit("Loki", 60, 60);

	while (unit1.GetAlive() && unit2.GetAlive()) {
		unit1.Attack(unit2);
		unit2.Attack(unit1);
	}

	cin.get();
}
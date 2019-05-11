#include <iostream>

#include "Unit.h"
#include "MeleeAttack.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));

	Unit herja = Unit("Herja", 40, 40);
	Unit loki = Unit("Loki", 60, 60);

	MeleeAttack ma = MeleeAttack(herja, "Slash"s, 0, 1.0f, 0.0f);
	herja.AttachAbility(&ma);

	while (herja.GetAlive() && loki.GetAlive()) {
		herja.UseAbility(loki, 0);
		loki.Attack(herja);
	}

	cin.get();
}
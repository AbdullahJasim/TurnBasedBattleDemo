#include <iostream>

#include "Unit.h"
#include "MeleeAttack.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));

	Unit herja("Herja", 40, 40);
	Unit loki("Loki", 200, 60);

	MeleeAttack ma(herja, "Slash"s, 0, 1.0f, 0.0f);
	herja.AttachAbility(&ma);
	herja.SetLuck(90);

	loki.SetAmor(10);

	while (herja.GetAlive() && loki.GetAlive()) {
		herja.UseAbility(loki, 0);
		//loki.Attack(herja);
	}

	cin.get();
}
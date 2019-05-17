#include <iostream>

#include "Unit.h"
#include "Slash_MeleeAttack.h"
#include "Blunt_MeleeAttack.h"
#include "Herja.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));

	Herja herja(2000, 40, 30, 10, 10, 20, 20, 20);

	Unit loki("Loki", 2000, 60);
	loki.SetArmor(10);
	
	Blunt_MeleeAttack hs(loki, "Head Smash"s, 0, 1.0f, 0.0f);
	loki.AttachAbility(&hs);

	while (loki.GetAlive() && herja.GetAlive()) {
		if (!herja.GetIsStunned()) {
			herja.Slash(loki);
			herja.Shoot(loki);
		} else {
			cout << "Herja is stunned and unable to take action." << endl;
			herja.SetIsStunned(false);
		}

		loki.UseAbility(herja, 0);
	}

	cin.get();
}
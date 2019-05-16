#include <iostream>

#include "Unit.h"
#include "MeleeAttack.h"
#include "HeadSmash.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));

	Unit herja("Herja", 200, 40);
	herja.SetLuck(30);
	herja.SetIsStunned(false);

	Unit loki("Loki", 200, 60);
	loki.SetAmor(10);

	MeleeAttack ma(herja, "Slash"s, 0, 1.0f, 0.0f);
	herja.AttachAbility(&ma);
	
	HeadSmash hs(loki, "Head Smash"s, 0, 1.0f, 0.0f);
	loki.AttachAbility(&hs);

	while (herja.GetAlive() && loki.GetAlive()) {
		if (!herja.GetIsStunned()) {
			herja.UseAbility(loki, 0);
		} else {
			cout << "Herja is stunned and unable to take action." << endl;
			(herja.SetIsStunned(false));
		}

		loki.UseAbility(herja, 0);
	}

	cin.get();
}
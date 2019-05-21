#include <iostream>

#include "Unit.h"
#include "Slash_MeleeAttack.h"
#include "Blunt_MeleeAttack.h"
#include "Herja.h"
#include "Board.h"
#include <time.h>

using namespace std;

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	shared_ptr<Herja> herja = make_shared<Herja>(2000, 40, 30, 10, 10, 20, 20, 20);

	shared_ptr<Unit> loki = make_shared<Unit>("Loki", 2000, 60);
	loki->SetArmor(10);
	
	Blunt_MeleeAttack hs(*loki, "Head Smash"s, 0, 1.0f, 0.0f);
	loki->AttachAbility(&hs);
	loki->SetLuck(0);

	Unit empty("Empty Space", 0, 0);

	Board board;
	board.SetUnitAtSlot(make_pair(0, 1), herja);
	//herja = board.GetUnitAtSlot(make_pair(0, 1));
	//herja->SetDamage(0);
	cout << loki->GetDamage();
	
	pair<int, int> herjaPos;
	while (loki->GetAlive() && herja->GetAlive()) {
		//If Loki has not queued an attack
		if (!loki->GetIsAttacking()) {
			//Loki will find the slot Herja is at
			herjaPos = herja->GetPosition();

			//Loki will highlight that slot for attack for next turn
			board.SelectSlot(herjaPos);
			loki->SetIsAttacking(true);
		} else {
			//Next turn, board will check if that slot has a valid target
			//If yes, facilitate attack
			//board.FacilitateAttack(loki, herjaPos);
			if (herja->GetPosition() == herjaPos) loki->UseAbility(*herja, 0);
			loki->SetIsAttacking(false);
		}
	}

	cin.get();
}
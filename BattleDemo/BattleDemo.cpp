#include <iostream>

#include "Unit.h"
#include "Slash_MeleeAttack.h"
#include "Blunt_MeleeAttack.h"
#include "Herja.h"
#include "Board.h"
#include <time.h>

using namespace std;

int GetSelection(int low, int high) {
	int selection = 0;

	while (selection < low || selection > high) {
		cin >> selection;
		cout << selection << endl;
	}

	return selection;
}

void MoveHerja(Board& board, shared_ptr<Herja> herja, int dx, int dy) {
	int y = herja->GetPosition().first;
	int x = herja->GetPosition().second;

	if (dy < 0 && y <= 0 ||
		dy > 0 && y >= board.GetHeight() - 1||
		dx <0 && x <= 0 ||
		dx > 0 && x >= board.GetWidth() - 1)
	return;

	board.SetUnitAtSlot(make_pair(y, x), nullptr);
	y += dy;
	x += dx;
	board.SetUnitAtSlot(make_pair(y, x), herja);
	herja->SetPosition(make_pair(y, x));
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	shared_ptr<Herja> herja = make_shared<Herja>(100, 40, 30, 10, 10, 20, 20, 20);

	shared_ptr<Unit> loki = make_shared<Unit>("Loki", 2000, 60);
	loki->SetArmor(10);
	
	Blunt_MeleeAttack hs(*loki, "Head Smash"s, 0, 1.0f, 0.0f);
	loki->AttachAbility(&hs);
	loki->SetLuck(0);
	loki->SetIsAttacking(false);

	Unit empty("Empty Space", 0, 0);

	Board board;
	board.SetUnitAtSlot(make_pair(2, 1), herja);
	
	pair<int, int> herjaPos;
	while (loki->GetAlive() && herja->GetAlive()) {
		board.PrintBoard();
		cout << "1 - Attack" << endl;
		cout << "2 - Move" << endl;


		int selection = GetSelection(1, 2);

		switch (selection) {
		case 1:
			cout << "1 - Melee Attack" << endl;
			cout << "2 - Gunshot" << endl;
			selection = GetSelection(1, 2);
			herja->UseAbility(*loki, selection - 1);
			break;

		case 2:
			cout << "1 - Up" << endl;
			cout << "2 - Down" << endl;
			cout << "3 - Left" << endl;
			cout << "4 - Right" << endl;

			int y = herja->GetPosition().first;
			int x = herja->GetPosition().second;

			selection = GetSelection(1, 4);

			switch (selection) {
			case 1:
				MoveHerja(board, herja, 0, -1);
				break;

			case 2:
				MoveHerja(board, herja, 0, 1);
				break;

			case 3:
				MoveHerja(board, herja, -1, 0);
				break;

			case 4:
				MoveHerja(board, herja, 1, 0);
				break;
			}

			break;
		}


		//If Loki has not queued an attack
		if (!loki->GetIsAttacking()) {
			//Loki will find the slot Herja is at
			herjaPos = herja->GetPosition();

			//Loki will highlight that slot for attack for next turn
			board.SelectSlot(herjaPos);
			loki->SetIsAttacking(true);
			cout << "Loki prepares to attack " << herjaPos.first << " - " << herjaPos.second << "." << endl;
		} else {
			//Next turn, board will check if that slot has a valid target
			//If yes, facilitate attack
			//board.FacilitateAttack(loki, herjaPos);
			if (herja->GetPosition() == herjaPos) loki->UseAbility(*herja, 0);
			loki->SetIsAttacking(false);
		}
	}
}
#include "Board.h"

Board::Board() {
	Board(3, 3);
}

Board::Board(int height, int width) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			Slot s();
			//m_SlotMapping.insert();
		}
	}
}

Unit& Board::GetUnitAtSlot(std::pair<int, int> targetSlot) {

}

void Board::SetUnitAtSlot(std::pair<int, int> targetSlot, Unit& unit) {

}

void Board::HighlightSlot(std::pair<int, int> targetSlot) {

}

void Board::FacilitateAttack(Unit& attacker, std::pair<int, int> targetSlot) {

}
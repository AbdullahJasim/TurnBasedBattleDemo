#include "Board.h"

using namespace std;

Board::Board(int height, int width) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			Slot* s = new Slot();
			m_Slots.insert(make_pair(make_pair(i, j), s));
		}
	}
}

Board::~Board() {
	for (auto slot: m_Slots) {
		delete slot.second;
		slot.second = nullptr;
	}
}


void Board::SetUnitAtSlot(std::pair<int, int> targetSlot, std::shared_ptr<Unit> unit) {
	auto it = m_Slots.find(targetSlot);
	if (it == m_Slots.end()) return;

	Slot* s = it->second;
	s->m_Unit = unit;
	//s->PrintUnit();
}

shared_ptr<Unit> Board::GetUnitAtSlot(std::pair<int, int> targetSlot) {
	auto it = m_Slots.find(targetSlot);
	if (it == m_Slots.end()) {
		Unit u;
		return nullptr;
	};

	Slot* s = it->second;
	//s->PrintUnit();
	return s->m_Unit;
}


void Board::SelectSlot(std::pair<int, int> targetSlot) {
	auto it = m_Slots.find(targetSlot);
	if (it == m_Slots.end()) {
		return;
	};

	it->second->m_IsHighlighted = true;
}
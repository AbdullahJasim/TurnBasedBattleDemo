#pragma once

#include <unordered_map>
#include "Unit.h"

class Board {
public:
	Board();
	Board(int height, int width);

	Unit& GetUnitAtSlot(std::pair<int, int> targetSlot);
	void SetUnitAtSlot(std::pair<int, int> targetSlot, Unit& unit);
	void HighlightSlot(std::pair<int, int> targetSlot);
	void FacilitateAttack(Unit& attacker, std::pair<int, int> targetSlot);

private:
	class Slot {
	public:
		bool IsHighlighted;
		Unit& unit;
	};

	std::vector<Slot> m_Slots;
	std::unordered_map<std::pair<int, int>, Slot> m_SlotMapping;
};
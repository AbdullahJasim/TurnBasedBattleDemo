#pragma once

#include <map>
#include "Unit.h"

class Board {
public:
	Board(int height = 3, int width = 3);
	virtual ~Board();

	std::shared_ptr<Unit> GetUnitAtSlot(std::pair<int, int> targetSlot);
	void SetUnitAtSlot(std::pair<int, int> targetSlot, std::shared_ptr<Unit> unit);
	void SelectSlot(std::pair<int, int> targetSlot);
	void FacilitateAttack(Unit& attacker, std::pair<int, int> targetSlot);

private:
	class Slot {
	public:
		Slot() {};
		bool IsHighlighted;
		std::shared_ptr<Unit> m_Unit;

		void PrintUnit() { 
			std::cout << m_Unit->GetName() << " has " << m_Unit->GetDamage() << " damage." << std::endl;
		};
	};
	//end of slot class

	std::map<std::pair<int, int>, Slot*> m_Slots;
};
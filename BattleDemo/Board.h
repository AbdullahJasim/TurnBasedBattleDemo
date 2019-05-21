#pragma once

#include <map>
#include "Unit.h"

class Board {
public:
	Board(int height = 3, int width = 3);
	virtual ~Board();

	int GetWidth() const { return m_Width; };
	int GetHeight() const { return m_Height; };

	std::shared_ptr<Unit> GetUnitAtSlot(std::pair<int, int> targetSlot);
	void SetUnitAtSlot(std::pair<int, int> targetSlot, std::shared_ptr<Unit> unit);
	void SelectSlot(std::pair<int, int> targetSlot);
	//void FacilitateAttack(std::shared_ptr<Unit> unit, std::pair<int, int> targetSlot);
	void PrintBoard();

private:
	class Slot {
	public:
		Slot() { m_Unit = nullptr; };
		bool m_IsHighlighted;
		std::shared_ptr<Unit> m_Unit;

		void PrintUnit() { 
			std::cout << m_Unit->GetName() << " has " << m_Unit->GetDamage() << " damage." << std::endl;
		};
	};
	//end of slot class

	std::map<std::pair<int, int>, Slot*> m_Slots;
	int m_Width, m_Height;
};
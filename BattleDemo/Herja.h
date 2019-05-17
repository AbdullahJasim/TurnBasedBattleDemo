#pragma once

#include <unordered_map>
#include "Unit.h"
#include "Slash_MeleeAttack.h"
#include "Piercing_RangeAttack.h"

class Herja : public Unit {
public:
	Herja();
	Herja(int HP, int damage, int luck, int armor, int magicResist, int fireResist, int iceResist, int shockResist);

	//copying isn't useful in this context
	Herja(const Herja& src) = delete;
	Herja& operator=(const Herja& src) = delete;

	virtual ~Herja();

	std::pair<int, int> GetPosition() const { return m_CurrentPosition; };
	void SetPosition(std::pair<int, int> pos) { m_CurrentPosition = pos; };

	virtual void Slash(Unit& target);
	virtual void Shoot(Unit& target);
	virtual bool HasBullets();

private:
	int m_Bullets;
	std::pair<int, int> m_CurrentPosition;
	std::unordered_map<std::string, int> m_SkillMapping;

	void SetupAbilities();
};
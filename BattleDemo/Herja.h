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

	virtual void Slash(Unit& target);
	virtual void Shoot(Unit& target);
	virtual bool HasBullets();

private:
	int m_CurrentPosition, m_Bullets;
	std::unordered_map<std::string, int> m_SkillMapping;

	void SetupAbilities();
};
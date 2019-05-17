#pragma once

#include "Ability.h"

class Piercing_RangeAttack : public Ability {
public:
	Piercing_RangeAttack(Unit& owner, std::string name, int turns, float physMod, float magMod);

	~Piercing_RangeAttack() override;

	virtual void Apply(Unit& target);
	virtual void Trigger(Unit& target);
private:

};
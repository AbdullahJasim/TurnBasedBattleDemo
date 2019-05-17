#pragma once

#include "Ability.h"

class Blunt_MeleeAttack : public Ability {
public:
	Blunt_MeleeAttack(Unit& owner, std::string name, int turns, float physMod, float magMod);

	~Blunt_MeleeAttack() override;

	virtual void Apply(Unit& target);
	virtual void Trigger(Unit& target);
private:

};
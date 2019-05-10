#pragma once

#include "Ability.h"

class MeleeAttack : public Ability {
public:
	MeleeAttack(Unit& owner, std::string name, int turns, float physMod, float magMod);

	~MeleeAttack() override;

	virtual void Apply(Unit& target);
	virtual void Trigger(Unit& target);
private:

};
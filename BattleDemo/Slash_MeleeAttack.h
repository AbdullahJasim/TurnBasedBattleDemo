#pragma once

#include "Ability.h"

class Slash_MeleeAttack : public Ability {
public:
	Slash_MeleeAttack(Unit& owner, std::string name, int turns, float physMod, float magMod);

	~Slash_MeleeAttack() override;

	virtual void Apply(Unit& target);
	virtual void Trigger(Unit& target);
private:
	
};
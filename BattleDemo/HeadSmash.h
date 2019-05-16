#pragma once

#include "Ability.h"

class HeadSmash : public Ability {
public:
	HeadSmash(Unit& owner, std::string name, int turns, float physMod, float magMod);

	~HeadSmash() override;

	virtual void Apply(Unit& target);
	virtual void Trigger(Unit& target);
private:

};
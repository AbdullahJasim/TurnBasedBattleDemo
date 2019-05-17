#include "Piercing_RangeAttack.h"
#include "Unit.h"

using namespace std;

Piercing_RangeAttack::Piercing_RangeAttack(Unit& owner, std::string name, int turns, float physMod, float magMod) :
	Ability(owner, name, turns, physMod, magMod)
{
}

Piercing_RangeAttack::~Piercing_RangeAttack() {}

void Piercing_RangeAttack::Apply(Unit& target) {
	Print();
	Damage d(GetOwner().GetDamage() * GetPhysMod(), 5.0, 0.0, 20.0, Damage::PHYSICAL, Damage::PIERCING, Damage::NONE);
	d.SetFluctuation(GetOwner().GetLuck());
	target.ApplyDamage(d, GetOwner());
}

void Piercing_RangeAttack::Trigger(Unit& target) {
	cout << "No trigger for " << GetName() << endl;
}
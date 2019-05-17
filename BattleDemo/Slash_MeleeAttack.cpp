#include "Slash_MeleeAttack.h"
#include "Unit.h"

using namespace std;

Slash_MeleeAttack::Slash_MeleeAttack(Unit& owner, std::string name, int turns, float physMod, float magMod) :
	Ability(owner, name, turns, physMod, magMod)
{
}

Slash_MeleeAttack::~Slash_MeleeAttack() {}

void Slash_MeleeAttack::Apply(Unit& target) {
	Print();
	Damage d(GetOwner().GetDamage() * GetPhysMod(), 10.0, 0.0, 0.0, Damage::PHYSICAL, Damage::SLASHING, Damage::NONE);
	d.SetFluctuation(GetOwner().GetLuck());
	target.ApplyDamage(d, GetOwner());
}

void Slash_MeleeAttack::Trigger(Unit& target) {
	cout << "No trigger for " << GetName() << endl;
}
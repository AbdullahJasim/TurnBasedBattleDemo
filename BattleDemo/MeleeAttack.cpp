#include "MeleeAttack.h"
#include "Unit.h"

using namespace std;

MeleeAttack::MeleeAttack(Unit& owner, std::string name, int turns, float physMod, float magMod) : 
	Ability(owner, name, turns, physMod, magMod)
{
}

MeleeAttack::~MeleeAttack() {}

void MeleeAttack::Apply(Unit& target) {
	Print();
	Damage d(40, 10.0, 0.0, 0.0, Damage::PHYSICAL, Damage::SLASHING, Damage::NONE);
	d.SetFluctuation(GetOwner().GetLuck());
	target.ApplyDamage(d, GetOwner());
}

void MeleeAttack::Trigger(Unit& target) {
	cout << "No trigger for " << GetName() << endl;
}
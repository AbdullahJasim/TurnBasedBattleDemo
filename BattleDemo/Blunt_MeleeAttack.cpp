#include "Blunt_MeleeAttack.h"
#include "Unit.h"

using namespace std;

Blunt_MeleeAttack::Blunt_MeleeAttack(Unit& owner, std::string name, int turns, float physMod, float magMod) :
	Ability(owner, name, turns, physMod, magMod)
{
}

Blunt_MeleeAttack::~Blunt_MeleeAttack() {}

void Blunt_MeleeAttack::Apply(Unit& target) {
	Print();
	Damage d(static_cast<int>(GetOwner().GetDamage() * GetPhysMod()), 0, 20, 0, Damage::PHYSICAL, Damage::BLUNT, Damage::NONE);
	d.SetFluctuation(GetOwner().GetLuck());
	target.ApplyDamage(d, GetOwner());
}

void Blunt_MeleeAttack::Trigger(Unit& target) {
	cout << "No trigger for " << GetName() << endl;
}
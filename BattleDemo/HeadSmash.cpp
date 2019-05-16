#include "HeadSmash.h"
#include "Unit.h"

using namespace std;

HeadSmash::HeadSmash(Unit& owner, std::string name, int turns, float physMod, float magMod) :
	Ability(owner, name, turns, physMod, magMod)
{
}

HeadSmash::~HeadSmash() {}

void HeadSmash::Apply(Unit& target) {
	Print();
	Damage d(20, 0.0, 20.0, 0.0, Damage::PHYSICAL, Damage::BLUNT, Damage::NONE);
	d.SetFluctuation(GetOwner().GetLuck());
	target.ApplyDamage(d, GetOwner());
}

void HeadSmash::Trigger(Unit& target) {
	cout << "No trigger for " << GetName() << endl;
}
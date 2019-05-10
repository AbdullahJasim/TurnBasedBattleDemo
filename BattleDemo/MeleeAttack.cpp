#include "MeleeAttack.h"

using namespace std;

MeleeAttack::MeleeAttack(Unit& owner, std::string name, int turns, float physMod, float magMod) : 
	Ability(owner, name, turns, physMod, magMod)
{
}

MeleeAttack::~MeleeAttack() {}

void MeleeAttack::Apply(Unit& target) {
	//m_Owner.attack(target);
	Print();
}

void MeleeAttack::Trigger(Unit& target) {
	cout << "No trigger for " << GetName() << endl;
}
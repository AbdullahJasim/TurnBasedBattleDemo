#include "Unit.h"

using namespace std;

//ctor
Unit::Unit() :
	m_Name("Unit"),
	m_Damage(10),
	m_HP(40),
	m_IsAlive(true)
{}

Unit::Unit(string name, int HP, int damage) : 
	m_Name(name),
	m_HP(HP),
	m_Damage(damage),
	m_IsAlive(true)
{}

//dtor
Unit::~Unit() {}

//copy ctors
Unit::Unit(const Unit& src) :
	m_Name(src.GetName()),
	m_HP(src.GetHP()),
	m_Damage(src.GetDamage()),
	m_IsAlive(src.GetAlive())
{}

Unit& Unit::operator=(const Unit& src) {
	if (this == &src) return *this;

	CopyFrom(src);
	return *this;
}

//move ctors
Unit::Unit(Unit&& other) {}

Unit& Unit::operator=(Unit&& other) { return *this; }

//helper functions for structors
void Unit::CopyFrom(const Unit& src) {
	SetName(src.GetName());
	SetHP(src.GetHP());
	SetDamage(src.GetDamage());
	m_IsAlive = src.GetAlive();
}

void Unit::FreeMemory() {

}

void Unit::MoveFrom(Unit&& src) {

}

void Unit::AttachAbility(Ability* ability) {
	//need to take in a copy and create a pointer
	m_Abilities.push_back(ability);
}

vector<Ability*> Unit::GetAbilities() {
	return m_Abilities;
}

void Unit::UseAbility(Unit& target, int abilityIndex) {
	m_Abilities.at(abilityIndex)->Apply(target);
}

//unit functions
void Unit::Print() const {
	cout << "Unit: " << GetName() << endl;
	cout << "HP: " << GetHP() << " - Damage: " << GetDamage() << endl;
}

void Unit::Attack(Unit& other) const {
	//other.ApplyDamage(m_Damage, *this);
}

bool Unit::ApplyDamage(Damage& d, const Unit& source) {
	int damage = CalculateDamage(d);
	if (damage <= 0) damage = 0;

	cout << "Unit " << source.GetName() << " attacks " << GetName() << " for " << damage << " points." << endl;

	if (damage >= GetHP()) {
		Die();
		return true;
	}


	SetHP(GetHP() - damage);
	return false;
}

void Unit::Die() {
	cout << "Unit " << GetName() << " died." << endl;
	SetHP(0);
	SetDamage(0);
	m_IsAlive = false;
}

int Unit::CalculateDamage(Damage& d) {
	int baseDamage = d.GetDamage();
	int finalDamage = 0;

	switch (d.GetDamageType()) {
	case Damage::PHYSICAL:
		CalculatePhysicalDamage(d);
		finalDamage = d.GetFinalDamage();
		break;
	case Damage::MAGICAL:
		break;
	default:
		break;
	}

	return d.GetFinalDamage();
}

int Unit::CalculatePhysicalDamage(Damage& d) {
	int randChance = 0;
	int fluctuation = 0;

	//blunt damage will lose twice as much armor the unit has in damage
	//slashing will lose only 1
	//pierce will lose the difference between the unit's armor and its pierce value, with a min of 0

	//blunt damage can stun
	//all damage types can crit
	switch (d.GetPhysicalType()) {
	case Damage::BLUNT:
		d.SetFinalDamage(d.GetDamage() - (2* GetArmor()));

		randChance = rand() % 100;
		if (randChance <= d.GetStun()) SetIsStunned(true);//d.SetIsStun(true);

		break;
	case Damage::SLASHING:
		d.SetFinalDamage(d.GetDamage() - GetArmor());
		break;
	case Damage::PIERCING:
		int remainingArmor = GetArmor() - d.GetPierce();
		if (0 > remainingArmor) remainingArmor = 0;
		d.SetFinalDamage(d.GetDamage() - remainingArmor);
		break;
	}

	randChance = rand() % 100;
	if (randChance <= d.GetCrit()) {
		d.SetIsCrit(true);
		d.SetFinalDamage(d.GetFinalDamage() * 2);
	}

	if (d.GetFinalDamage() != 0) randChance = rand() % d.GetFinalDamage();
	randChance *= d.GetFluctuation();
	randChance /= 100;
	fluctuation = static_cast<int>(randChance);
	fluctuation = abs(fluctuation);

	randChance = rand() % 100;
	if (randChance >= 50) {
		d.SetFinalDamage(d.GetFinalDamage() + fluctuation);
	} else {
		d.SetFinalDamage(d.GetFinalDamage() - fluctuation);
	}

	return 0;
}
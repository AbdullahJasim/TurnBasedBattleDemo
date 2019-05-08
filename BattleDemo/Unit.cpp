#include "Unit.h"

using namespace std;

//ctor
Unit::Unit() {
	SetName("Unit");
	SetDamage(10);
	SetHP(40);
	m_IsAlive = true;
}

Unit::Unit(string name, int HP, int damage) {
	SetName(name);
	SetHP(HP);
	SetDamage(damage);
	m_IsAlive = true;
}

//dtor
Unit::~Unit() {

}

//copy ctors
Unit::Unit(const Unit& src) {
	CopyFrom(src);
}

Unit& Unit::operator=(const Unit& src) {
	if (this == &src) return *this;

	CopyFrom(src);
	return *this;
}

//move ctors
Unit::Unit(Unit&& other) {

}

Unit& Unit::operator=(Unit&& other) {
	return *this;
}

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

//setters and getters
string Unit::GetName() const {
	return m_Name;
}

void Unit::SetName(string name) {
	m_Name = name;
}

int Unit::GetDamage() const {
	return m_Damage;
}

void Unit::SetDamage(int damage) {
	m_Damage = damage;
}

int Unit::GetHP() const {
	return m_HP;
}

void Unit::SetHP(int HP) {
	m_HP = HP;
}

bool Unit::GetAlive() const {
	return m_IsAlive;
}

//unit functions
void Unit::Print() const {
	cout << "Unit: " << GetName() << endl;
	cout << "HP: " << GetHP() << " - Damage: " << GetDamage() << endl;
}

void Unit::Attack(Unit& other) const {
	other.ApplyDamage(m_Damage, *this);
}

bool Unit::ApplyDamage(int damage, const Unit& source) {
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
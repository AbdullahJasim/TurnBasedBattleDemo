#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Ability.h"

class Unit {
public:
	//ctor dtor
	Unit();
	Unit(std::string name, int HP, int damage);
	virtual ~Unit();

	//cpy ctors
	Unit(const Unit& src);
	Unit& operator=(const Unit& src);

	//move ctors
	Unit(Unit&& other);
	Unit& operator=(Unit&& other);

	//getters and setters
	std::string GetName() const;
	void SetName(std::string name);
	int GetDamage() const;
	void SetDamage(int damage);
	int GetHP() const;
	void SetHP(int HP);
	bool GetAlive() const;

	void AttachAbility(Ability* ability);
	std::vector<Ability*> GetAbilities();
	void UseAbility(Unit& target, int abilityIndex);

	//prints information about unit
	virtual void Print() const;

	//inflicts damage on the target unit
	virtual void Attack(Unit& other) const;

	//reduces HP and returns true if unit dies
	virtual bool ApplyDamage(int damage, const Unit& source);

	//cleans unit properties before killing it
	virtual void Die();
private:
	std::string m_Name;
	bool m_IsAlive, m_CanAttack;
	int m_HP, m_Damage, m_TurnsToAttack;
	int m_Armor;
	std::vector<Ability*> m_Abilities;

	virtual void CopyFrom(const Unit& src);
	virtual void FreeMemory();
	virtual void MoveFrom(Unit&& src);
};
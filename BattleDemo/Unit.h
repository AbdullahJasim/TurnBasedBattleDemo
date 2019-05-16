#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Ability.h"

class Unit {
public:
	//ctors
	Unit();
	Unit(std::string name, int HP, int damage);

	//cpy ctors
	Unit(const Unit& src);
	Unit& operator=(const Unit& src);

	//move ctors
	Unit(Unit&& other);
	Unit& operator=(Unit&& other);

	//dtor
	virtual ~Unit();

	//getters and setters
	std::string GetName() const { return m_Name; };
	void SetName(std::string name) { m_Name = name; };
	int GetDamage() const { return m_Damage; };
	void SetDamage(int damage) { m_Damage = damage; };
	int GetHP() const { return m_HP; };
	void SetHP(int HP) { m_HP = HP; };
	bool GetAlive() const { return m_IsAlive; };
	bool GetIsStunned() const { return m_IsStunned; };
	void SetIsStunned(bool isStunned) { m_IsStunned = isStunned; };
	int GetLuck() const { return m_Luck; };
	void SetLuck(int luck) { m_Luck = luck; };

	int GetArmor() const { return m_Armor; };
	void SetArmor(int armor) { m_Armor = armor; };
	int GetMagicResist() const { return m_MagicResist; };
	void SetMagicResist(int magicResist) { m_MagicResist = magicResist; };
	int GetFireResist() const { return m_FireResist; }
	void SetFireResist(int fireResist) { m_FireResist = fireResist; };
	int GetIceResist() const { return m_IceResist; };
	void SetIceResist(int iceResist) { m_IceResist = iceResist; };
	int GetShockResist() const { return m_ShockResist; };
	void SetShockResist(int shockResist) { m_ShockResist = shockResist; };

	//battle functions
	virtual void Attack(Unit& other) const;
	void AttachAbility(Ability* ability);
	std::vector<Ability*> GetAbilities();
	void UseAbility(Unit& target, int abilityIndex);
	virtual bool ApplyDamage(Damage& d, const Unit& source);

	virtual void Print() const;
	virtual void Die();

protected:
	std::string m_Name;
	bool m_IsAlive, m_CanAttack, m_IsStunned;
	int m_HP, m_Damage, m_TurnsToAttack, m_Luck;
	int m_Armor, m_MagicResist, m_FireResist, m_IceResist, m_ShockResist;
	std::vector<Ability*> m_Abilities;

	virtual int CalculateDamage(Damage& d);
	int CalculatePhysicalDamage(Damage& d);

private:
	virtual void CopyFrom(const Unit& src);
	virtual void FreeMemory();
	virtual void MoveFrom(Unit&& src);
};
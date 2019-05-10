#pragma once

#include <string>
#include <vector>
#include <iostream>

class Unit;

class Ability {
public:
	Ability(Unit& owner, std::string name, int turns, float physMod, float magMod);
	virtual ~Ability();

	Ability(const Ability& src);
	//no copy assignment operator will be supported for this, as it makes little sense
	//Ability& operator=(const Ability& src);

	Unit& GetOwner() const;
	std::string GetName() const;
	void SetName(std::string);
	int GetTurns() const;
	void SetTurns(int turns);
	float GetPhysMod() const;
	void SetPhysMod(float mod);
	float GetMagMod() const;
	void SetMagMod(float mod);
	
	virtual void Apply(Unit& target) = 0;
	virtual void Trigger(Unit& target) = 0;
protected:
	std::string m_Name;
	int m_TurnsToCast;
	float m_PhysicalModifier, m_MagicModifier;

	//for easier access to owner's values, owner is references
	//this creates a double reference, owner to ability and ability to owner which might be problematic
	Unit& m_Owner;

	virtual void Print() const;
};
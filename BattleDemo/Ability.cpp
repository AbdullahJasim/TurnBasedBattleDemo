#include "Ability.h"

using namespace std;

Ability::Ability(Unit& owner, string name, int turns, float physMod, float magMod) :
	m_Name(name),
	m_TurnsToCast(turns),
	m_PhysicalModifier(physMod),
	m_MagicModifier(magMod),
	m_Owner(owner)
{
}

/*
Ability::Ability(const Ability& src) :
	m_Name(src.GetName()),
	m_TurnsToCast(src.GetTurns()),
	m_PhysicalModifier(src.GetPhysMod()),
	m_MagicModifier(src.GetMagMod()),
	m_Owner(src.GetOwner())
{
}
*/

Ability::~Ability() {}

//setters and getters
Unit& Ability::GetOwner() const { return m_Owner; };
string Ability::GetName() const { return m_Name; };
void Ability::SetName(string name) { m_Name = name; };
int Ability::GetTurns() const { return m_TurnsToCast; };
void Ability::SetTurns(int turns) { m_TurnsToCast = turns; };
float Ability::GetPhysMod() const { return m_PhysicalModifier; };
void Ability::SetPhysMod(float mod) { m_PhysicalModifier = mod; };
float Ability::GetMagMod() const { return m_MagicModifier; };
void Ability::SetMagMod(float mod) { m_MagicModifier = mod; };

void Ability::Print() const {
	cout << "Ability " << GetName() << " was cast, ";
}
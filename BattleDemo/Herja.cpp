#include "Herja.h"

using namespace std;

Herja::Herja() {

}

Herja::Herja(int damage, int HP, int luck, int armor, int magicResist, int fireResist, int iceResist, int shockResist) :
	Unit("Herja", 100, damage)
{
	SetLuck(luck);
	SetArmor(armor);
	SetMagicResist(magicResist);
	SetFireResist(fireResist);
	SetIceResist(iceResist);
	SetShockResist(shockResist);
	SetupAbilities();
}

Herja::~Herja() {
	for (auto ability: m_Abilities) {
		delete ability;
	}
}

void Herja::Slash(Unit& target) {
	auto it = m_SkillMapping.find("Slash");
	if (it != m_SkillMapping.end()) UseAbility(target, it->second);
}

void Herja::Shoot(Unit& target) {
	auto it = m_SkillMapping.find("Shoot");
	if (it != m_SkillMapping.end()) UseAbility(target, it->second);
}

void Herja::SetupAbilities() {
	int i = 0;

	Slash_MeleeAttack* ma = new Slash_MeleeAttack(*this, "Slash"s, 0, 1.0f, 0.0f);
	AttachAbility(ma);

	m_SkillMapping.insert(make_pair<string, int>("Slash", 0));
}
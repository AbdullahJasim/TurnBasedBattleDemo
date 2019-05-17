#include "Herja.h"

using namespace std;

Herja::Herja() {

}

Herja::Herja(int HP, int damage, int luck, int armor, int magicResist, int fireResist, int iceResist, int shockResist) :
	Unit("Herja", HP, damage)
{
	SetLuck(luck);
	SetArmor(armor);
	SetMagicResist(magicResist);
	SetFireResist(fireResist);
	SetIceResist(iceResist);
	SetShockResist(shockResist);
	SetupAbilities();

	m_Bullets = 6;
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
	if (it != m_SkillMapping.end()) {
		UseAbility(target, it->second);
		--m_Bullets;
	}
}

bool Herja::HasBullets() {
	return (m_Bullets > 0);
}

void Herja::SetupAbilities() {
	int i = 0;

	Slash_MeleeAttack* slash = new Slash_MeleeAttack(*this, "Slash"s, 0, 1.0f, 0.0f);
	m_SkillMapping.insert(make_pair<string, int>("Slash", 0));
	AttachAbility(slash);
	
	Piercing_RangeAttack* gunshot = new Piercing_RangeAttack(*this, "Gun Shot"s, 0, 1.0f, 0.0f);
	m_SkillMapping.insert(make_pair<string, int>("Shoot", 1));
	AttachAbility(gunshot);
}
#include "Damage.h"

Damage::Damage(int baseDamage, double crit, double stun, double pierce, DamageType damageType, PhysicalType physicalType, ElementType element) :
	m_BaseDamage(baseDamage),
	m_CritChance(crit),
	m_StunChance(stun),
	m_ArmorPierce(pierce),
	m_DamageType(damageType),
	m_PhysicalType(physicalType),
	m_Element(element)
{}
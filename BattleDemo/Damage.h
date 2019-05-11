#pragma once

class Damage {
public:
	enum DamageType { PHYSICAL, MAGICAL, };
	enum PhysicalType { SLASHING, PIERCING, BLUNT };
	enum ElementType { NONE, FIRE, ICE, SHOCK };

	Damage(int baseDamage, double crit, double stun, double pierce, DamageType damageType, PhysicalType physicalType, ElementType element);


	int GetDamage() const { return m_BaseDamage; };
	void SetDamage(int damage) { m_BaseDamage = damage; };
	double GetCrit() const { return m_CritChance; };
	void SetCrit(double crit) { m_CritChance = crit; };
	double GetStun() const { return m_StunChance; };
	void SetStun(double stun) { m_StunChance = stun; };
	double GetPierce() const { return m_ArmorPierce; };
	void SetPierce(double pierce) { m_ArmorPierce = pierce; };

	int GetFinalDamage() const { return m_FinalDamage; };
	void SetFinalDamage(int finalDamage) { m_FinalDamage = finalDamage; };
	bool GetIsCrit() { return m_IsCrit; };
	void SetIsCrit(bool isCrit) { m_IsCrit = isCrit; };
	bool GetWillStun() { return m_WillStun; };
	void SetIsStun(bool willStun) { m_WillStun = willStun; }

	DamageType GetDamageType() { return m_DamageType; };;
	void SetDamagaeType(DamageType damageType) { m_DamageType = damageType; };
	PhysicalType GetPhysicalType() { return m_PhysicalType; };
	void SetPhysicalType(PhysicalType physicalType) { m_PhysicalType = physicalType; };
	ElementType GetElement() { return m_Element; };
	void SetElement(ElementType element) { m_Element = element; };

private:
	int m_BaseDamage;
	DamageType m_DamageType;
	PhysicalType m_PhysicalType;
	ElementType m_Element;
	double m_CritChance, m_StunChance, m_ArmorPierce;

	int m_FinalDamage;
	bool m_IsCrit, m_WillStun;
};
#include "Character.h"

Character::Character() {
	health = 10;
	damage = 3;
}

string Character::GetName()
{
	return name;
}

void Character::SetName(string _name)
{
	name = _name;
}

int Character::GetHealth()
{
	return health;
}

void Character::IncreaseHealth(int increaseAmount)
{
	health += increaseAmount;
}

void Character::DecreaseHealth(int decreaseAmount)
{
	health -= decreaseAmount;
}

int Character::GetDamage()
{
	return damage;
}

void Character::IncreaseDamage(int increaseAmount)
{
	damage += increaseAmount;
}

void Character::LevelUp()
{
	IncreaseHealth(2);
	IncreaseDamage(1);
}

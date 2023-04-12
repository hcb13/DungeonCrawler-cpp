#include "Enemy.h"

int Enemy::GetHealth()
{
	return health;
}

void Enemy::SetHealth(int _health)
{
	health = _health;
}

int Enemy::GetDamage()
{
	return damage;
}

void Enemy::SetDamage(int _damage)
{
	damage = _damage;
}

Enemy::Sizes Enemy::GetSize()
{
	return size;
}

void Enemy::SetSize(Sizes _size)
{
	size = _size;
}

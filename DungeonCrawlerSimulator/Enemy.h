#pragma once
class Enemy
{
public:
	enum Sizes {
		SMALL = 0,
		MEDIUM = 1,
		BIG = 2
	};

	int GetHealth();
	void SetHealth(int _health);

	int GetDamage();
	void SetDamage(int _damage);

	Sizes GetSize();
	void SetSize(Sizes _size);

private:
	int health;
	int damage;
	Sizes size;

};


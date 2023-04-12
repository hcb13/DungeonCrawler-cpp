#pragma once

#include <string>

using namespace std;

class Character
{
private:
	string name;
	int health;
	int damage;

public:
	Character();

	string GetName();
	void SetName(string _name);

	int GetHealth();
	void IncreaseHealth(int increaseAmount);
	void DecreaseHealth(int decreaseAmount);

	int GetDamage();
	void IncreaseDamage(int increaseAmount);

	void LevelUp();
};


#include <iostream>

using namespace std;

struct Point // struktura, domysly dostep do public
{
	float x = 0.0f;
	float y = 0.0f;

	void Print()
	{
		cout << x << ", " << y << endl;
	}
};

Point GetPlayerPosition()
{
	Point p;
	p.x = 10;
	p.y = 20;

	return p;
}

struct CharacterStats
{
	int age = 0;
	int height = 0;
	char characterClass = ' ';

	int dexterity = 0;
	int strength = 0;
	int mana = 0;
	int health = 0;
};

class Character
{
public:
	CharacterStats GetStats() const
	{
		return m_stats;
	}

	void SetStats(const CharacterStats& stats)
	{
		m_stats = stats;
	}

protected:
	CharacterStats m_stats;
};



int main()
{
	Point playerPosition = GetPlayerPosition();
	playerPosition.Print();

	return 0;
}

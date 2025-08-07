#include <iostream>

using namespace std;

class Player {


	friend class Game;

protected:
	int m_health = 100;

};

class LocalPlayer : public Player
{
	friend class Game; // nie dziedziczymy przyjaüni !!

private:
	int m_controllerID = 50;
};

class Game {

public:
	
	void DisplayPlayerState(Player& player)
	{
		cout << "Player health: " << player.m_health << endl;
	}

	void DisplayLocalPlayerState(LocalPlayer& player)
	{
		cout << "Local Player controller ID: " << player.m_controllerID << endl;
	}
};

int main()
{
	Player player;
	LocalPlayer localplayer;

	Game game;

	game.DisplayPlayerState(player);
	game.DisplayLocalPlayerState(localplayer);

	
	
	return 0;
}
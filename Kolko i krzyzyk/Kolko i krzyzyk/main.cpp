#include <iostream>

using namespace std;

void Initialize();

void GetPlayerInput();
bool Update();
void Render();

void Shutdown();

int main()
{
	Initialize();

	while (true)
	{
		GetPlayerInput();
		if (!Update())
		{
			break;
		}
		Render();
	}

	Shutdown();
	
	return 0;
}

void Initialize()
{
	cout << "Witaj w grze Tic-Tac-Toe!" << endl;
}

void GetPlayerInput()
{

}

bool Update()
{
	return true;
}

void Render()
{

}

void Shutdown()
{
	cout << "Game over!" << endl;
}
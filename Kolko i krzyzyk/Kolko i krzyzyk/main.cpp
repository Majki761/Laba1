#include <iostream>

using namespace std;

char BOARD[3][3];
char currentPlayer = 'X';

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

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			BOARD[i][j] = '_';
		}
	}
}

void GetPlayerInput()
{
	int row, col;

	while (true)
	{
		cout << "Gracz" << currentPlayer << ", podaj wiersz (0-2) i kolumne (0-2): ";
		cin >> row >> col;

		if (row >= 0 && row < 3 && col >= 0 && col < 3)
		{
			if (BOARD[row][col] == '_')
			{
				BOARD[row][col] = currentPlayer;
				break;
			}
			else
			{
				cout << "To pole jest juz zajete! Sproboj ponownie. ";
			}
		}
		else
		{
			cout << "Wprowadzono zle wspolrzedne, sproboj ponownie.";
		}
	}
}
//sprawdzanie zwyciestwa i remisu

bool CheckWin(char player)
{
	//Wiersze i kolumny
	
	for (int i = 0; i < 3; ++i)
	{
		if ((BOARD[i][0] == player && BOARD[i][1] == player && BOARD[i][2] == player) || (BOARD[0][i] == player && BOARD[1][i] == player && BOARD[2][i] == player))
		    return true;
	}
	
	//Przekatne
	
	if ((BOARD[0][0] == player && BOARD[1][1] == player && BOARD[2][2] == player) || (BOARD[0][2] == player && BOARD[1][1] == player && BOARD[2][0] == player))
		return true;

	return false;
}

bool IsDraw()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (BOARD[i][j] == '_')
				return false;

	return true;
}

bool Update()
{
	if (CheckWin(currentPlayer))
	{
		Render();
		cout << "Gracz " << currentPlayer << " wygrywa!" << endl;
		return false;
	}
	else if (IsDraw())
	{
		Render();
		cout << "Remis!" << endl;
		return false;
	}

	// Zmiana gracza
	currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	
	return true;
}

void Render()
{
	system("cls");
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << BOARD[i][j];
		}
		cout << endl;
	}
}

void Shutdown()
{
	cout << "Game over!" << endl;
}
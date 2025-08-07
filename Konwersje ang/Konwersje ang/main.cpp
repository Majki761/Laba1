#include <iostream>

using namespace std;

float metry;

float ile_cali(float m)
{
	return m * 39.37;
}

float ile_jardow(float x);

void ile_mil(float m)
{
	cout << "Na mile: " << m * 0.0006213;
}


int main()
{
	cout << "Podaj ile metrow: ";
	cin >> metry;

	cout << "Na cale: " << ile_cali(metry) << endl;
	cout << "Na jardy: " << ile_jardow(metry) << endl;
	ile_mil(metry);
	
	return 0;
}

float ile_jardow(float x)
{
	return x * 1.0963;
}
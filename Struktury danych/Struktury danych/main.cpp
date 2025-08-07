#include <iostream>
#include <string>

using namespace std;

int main()
{
	string Hello = "Hello World!";
	cout << Hello << endl;
	cout << "Dlugosc stringa: " << Hello.length() << endl; // rozmiar stringa

	string welcomeMessage = "How are you?";
	string combinedString = Hello + ' ' + welcomeMessage; //laczenie stringow (nie do koñca wydajne)

	cout << combinedString << endl;

	cout << combinedString.substr(13, 12) << endl;

	if (string::npos == combinedString.find("year")) // znajdowanie podstringa
	{
		cout << "Substring not found" << endl;
	}
	else
	{
		cout << "Substring found at position: " << combinedString.find("are") << endl;
	}

	cout << combinedString[3] << endl; // dostep do elementu po indeksie

	return 0;
}
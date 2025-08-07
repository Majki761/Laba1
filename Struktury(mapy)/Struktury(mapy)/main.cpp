#include <iostream>
#include <map> // posortowana
#include <unordered_map> // bardziej wydajna (ale zyzywa wiecej pamieci)

using namespace std;

int main()
{
	std::map<string, int> ages;

	ages.insert(std::pair<string, int>("Ty", 40)); // dodanie nowej pary klucz-wartosc

	ages["Alice"] = 30; // dodanie nowej pary klucz-wartosc

	ages["Joe"] = 50;
	ages["Kevin"] = 5;
	ages["Zoe"] = 60;

	cout << "Ty's age: " << ages["Ty"] << endl;
	 
	ages["Ty"] = 43; // uaktualnienie wartosci pod danym kluczem

	cout << "Ty's age: " << ages["Ty"] << endl; // dostep do wartosci po kluczu

	for (auto elem : ages) // iterowanie po mapie
	{
		cout << elem.first << ", " << elem.second << endl;
	}

	ages.erase("Ty"); // usuwanie z mapy

    auto it = ages.find("Ty");

	if (it == ages.end()) // sprawdzenie czy element istnieje w mapie
	{
		cout << "element not found";
	}
	
    return 0;
}
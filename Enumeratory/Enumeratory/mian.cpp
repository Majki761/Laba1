#include <iostream>

using namespace std;

enum Animal
{
	Animal_Cat = 10, // 0	
	Animal_Dog = 30, // 1
	Animal_Lion // 2
};

enum Pet
{
	Pet_Cat,
	Pet_Dog,
	Pet_Hamster
};

enum  class Mammal : int // enumerator z zakresem
{
	Cat = 10, // 0
	Dog, // 1
	Dolphin // 2
};



int main()
{
	Animal animal = Animal_Lion;

	Pet pet = Pet_Cat;
	
	Mammal ssak = Mammal::Dolphin;

	switch (animal)
	{
	case Animal_Cat:
		cout << "This is cat" << endl;
		break;
	case Animal_Dog:
		cout << "This is dog" << endl;
		break;
	case Animal_Lion:
		cout << "This is Lion" << endl;
		break;
	}

	switch (ssak)
	{
	case Mammal::Cat:
		cout << "This is cat" << endl;
		break;
	case Mammal::Dog:
		cout << "This is dog" << endl;
		break;
	case Mammal::Dolphin:
		cout << "This is Dolphin" << endl;
		break;
	}

	cout << animal << endl;

	cout << (int)ssak << endl; // c-style casting
	return 0;
}
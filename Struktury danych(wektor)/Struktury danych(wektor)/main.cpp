#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyClass
{
public:
	MyClass(string n, int i) : name(n), id(i) {};
	string name;
	int id = 0;
};

int main()
{
	vector<int> Numbers = { 1, 2, 3, 4, 5 };

	Numbers.push_back(6);
	Numbers.push_back(7);
	Numbers.push_back(8);
	Numbers.push_back(9);
	Numbers.push_back(10);
	
	for (int i = 0;i < Numbers.size(); ++i)
	{
		cout << Numbers[i] << endl;
	}

	vector<string> Animals = { "dog", "cat", "lion" };

	Animals.push_back("boar");
	Animals.push_back("elephant");

	//iterowanie za pomoca zmiennej sterujacej
	cout << "Zmienna sterujaca:" << endl;
	for (int i = 0; i < Animals.size(); ++i)
	{
		cout << Animals[i] << endl;
	}
	// iterowanie za pomoca iteratora
	cout << "Iterator:" << endl;
	for (vector<string>::iterator it = Animals.begin(); it != Animals.end(); ++it)
	{
		if (*it == "boar") // usuniecie ze srodka
		{
			it = Animals.erase(it);
		}
		
		cout << *it << endl;
		
	}

	Animals.pop_back(); // usuniecie z konca

	auto /*vector<string>::iterator it*/ it = Animals.begin(); // przyklad uzycia auto
	
	// range based for loop
	cout << "Range based loop:" << endl;
	for (string& animal : Animals)
	{
		cout << animal << endl;
	}

	//realokacja pamieci wektora

	vector<int> TestVector = { 1,2,3,4,5,6 };
	
	TestVector.push_back(7);
	cout << TestVector.capacity() << endl;

	TestVector.push_back(8);
	cout << TestVector.capacity() << endl;

	TestVector.push_back(9);
	cout << TestVector.capacity() << endl;

	TestVector.push_back(10);
	cout << TestVector.capacity() << endl;

	TestVector.reserve(200); // rezerwacja pamieci wektora
	
	for (int i = 0; i < 100; ++i)
	{
		TestVector.push_back(i);
		cout << TestVector.capacity() << endl;
	}
	
	TestVector.shrink_to_fit();
	cout << TestVector.capacity() << endl;


	// sortowanie wektora

	vector<int> TestVector2 = { 5,9,1,2,-45,0,100 };  // sortowac mozna tylko z operatorem porównania!!!

	std::sort(TestVector2.rbegin(), TestVector2.rend()); // rbegin i rend (przejscie od tylu iteratora)

	for (auto elem : TestVector2)
	{
		cout << elem << endl;
	}

	// sortowanie wektora kazdej klasy

	vector<MyClass> TestVector3;

	TestVector3.push_back(MyClass("Marek", 9));
	TestVector3.push_back(MyClass("Darek", 3));
	TestVector3.push_back(MyClass("Krzysiek", 0));
	TestVector3.push_back(MyClass("Maciek", 22));


	auto comparator = [/*przechytywanie zmiennych spoza lambdy*/](MyClass& a, MyClass& b) // wyrazenie lambda
		{
			return a.id < b.id;
		};

	std::sort(TestVector3.begin(), TestVector3.end(), comparator); // sortowanie z predykatorem (comparatorem)


	for (auto elem : TestVector3)
	{
		cout << elem.name << endl;
	}
	return 0;
}
#include <iostream>

using namespace std;

class Person // klasa g³ówna
{
public:
	Person() = default;

	Person(int age) : m_age(age)
	{
		m_age = age;
	}

    int GetAge()
	{
		return m_age;
	}

protected:
	int m_age = 0; // pole protected: klasy pochodne mog¹ mieæ do niego dostêp

private:
	int m_height = 0;
};

class Student : public Person // deklaracja klasy pochodnej
{
public:
	Student(int age, int indexNumber) : m_indexNumber(indexNumber)
	{
		m_age = age;
	}
	
	int GetIndexNumber()
	{
		return m_indexNumber;
	}

private:
	int m_indexNumber;
};


int main()
{
	Person osoba(18);

	cout << "wiek osoby to: " << osoba.GetAge() << endl;

	Student student(20, 9111);

	cout << "wiek studenta to: " << student.GetAge() << ", numer indexu to: " << student.GetIndexNumber() << endl;
	
	Student* student2 = new Student(22, 9222);

	cout << "wiek studenta 2 to: " << student2->GetAge() << ", numer indexu studenta 2 to: " << student2->GetIndexNumber() << endl;
	
	return 0;
}
#include <iostream>

using namespace std;

class Shape // klasa abstrakcyjna - zawiera conajmniej jedna metode czysto wirtualna
{
public:
	virtual float GetArea() = 0; // metoda czysto wirtualna
	
};

class Triangle : public Shape
{
public:
	Triangle() = default;
	
	Triangle(float height, float base) : m_height(height), m_base(base) {}
	
	
	float GetArea()
	{
		return m_base * m_height / 2.0f;
	}

protected:
	float m_height = 0;
	float m_base = 0;
};

class Rectangle : public Shape
{
public:
	Rectangle(float a, float b) : m_a(a), m_b(b){}

	float GetArea() 
	{
		return m_a * m_b;
	}

protected:
	float m_a = 0.0f;
	float m_b = 0.0f;
};

float SumAreas(Shape* Shapes[], int size) // przyklad poliformizmu
{
	float Sum = 0.0f;

	for (int i = 0; i < size; ++i)
	{
		Sum += Shapes[i]->GetArea();
	}

	return Sum;
}


int main()
{
	Shape* Shapes[5];

	Shapes[0] = new Rectangle(2.0, 5.0);
	Shapes[1] = new Rectangle(6.0, 20.0);
	Shapes[2] = new Triangle(2.0, 5.0);
	Shapes[3] = new Triangle(7.0, 6.0);
	Shapes[4] = new Triangle(4.0, 9.0);

	cout << SumAreas(Shapes, 5) << endl;
	
	return 0;
}
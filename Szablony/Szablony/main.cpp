#include <iostream>

using namespace std;

template<typename T> 
T mymax(T a, T b) // szablon funkcji
{
	return (a > b) ? a : b; // operator trynarny
	
	/* if (a > b)
	{
		return a;
	}
	else
		return b;
	*/
}

template <>
char mymax(char a, char b) // specjalizacja szablonu
{
	return (tolower(a) > tolower(b)) ? a : b;
}

class Animal
{
	int m_age = 0;
};

template<typename T, int size = 10> // domyœlne argumenty szbablonu klasy
class MyArray
{
public:
	T GetElement(int index)
	{
		return m_array[index];
	}

	void SetElement(int index, T data)
	{
		m_array[index] = data;
	}


private:
	T m_array[size];


};

int main()
{
	int A = 10;
	int B = 15;

	float C = 1.5f;
	float D = 5.5f;


	cout << mymax<int>(A, B) << endl;

	cout << mymax<float>(C, D) << endl;

	char G = 'g';
	char H = 'H';

	cout << mymax<char>(G, H) << endl;

	
	MyArray<int> array; // wywo³anie szablonu klasy

	for (int i = 0; i < 10; ++i)
	{
		array.SetElement(i, i);
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << array.GetElement(i) << ", ";
	}

	MyArray<float, 10000> array2;
	
	MyArray<Animal, 2> animals;

	return 0;
}
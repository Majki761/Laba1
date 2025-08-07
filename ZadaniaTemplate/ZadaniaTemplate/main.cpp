#include <iostream>

using namespace std;

template<typename T, typename U>
class Pair
{
public:
	T GetA()
	{
		return m_a;
	}

	void SetA(T a)
	{
		m_a = a;
	}

	U GetB()
	{
		return m_b;
	}

	void SetB(U b)
	{
		m_b = b;
	}

private:
	T m_a;
	U m_b;

};



int main()
{
	Pair<int, float> myPair;

	myPair.SetA(10);
	myPair.SetB(11.2f);

	cout << myPair.GetA() << endl << myPair.GetB() << endl;


	return 0;
}
#include <iostream>
#include <unordered_map>


using namespace std;

bool isUnique(const string& text)
{
	unordered_map<char, int> charMap;

	for (char elem : text)
	{
		if (charMap.find(elem) != charMap.end())
		{
			return false;
		}
		else
		{
			charMap[elem] = 1;
		}
		return true;
	}
}

int main()
{

	if (isUnique("aaabbb"))
	{
		cout << "test 1 failed" << endl;
	}
	else
	{
		cout << "test 1 succeded" << endl;
	}

	if (isUnique("abcdef"))
	{
		cout << "test 2 succeded" << endl;
	}
	else
	{
		cout << "test 2 failed" << endl;
	}
}
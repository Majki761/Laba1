#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>


using namespace std;

static int ExecutionCounter = 0;

int BinarySearchRecursive(const vector<int>& tab, int elem, int begin, int end)
{
    ExecutionCounter++;
	int middleIndex = (begin + end) / 2;

	if (tab[middleIndex] == elem)
	{
		return middleIndex;
	}

	if (elem < tab[middleIndex])
	{
		return BinarySearchRecursive(tab, elem, begin, middleIndex - 1);
	}
	else if (elem > tab[middleIndex])
	{
		return BinarySearchRecursive(tab, elem, middleIndex + 1, end);
	}


}

int BinarySearch(const vector<int>& tab, int elem)
{
	int begin = 0;
	int end = tab.size() - 1;
	
	while (begin < end)
	{
		int middleIndex = (begin + end) / 2;

		if (tab[middleIndex] == elem)
		{
			return middleIndex;
		}

		if (elem < tab[middleIndex])
		{
			end = middleIndex - 1;
		}
		else if (elem > tab[middleIndex])
		{
			begin = middleIndex + 1;
		}
	}

	return -1;
}


int main()
{
	vector<int> TAB = { 1,2,3,4,5,6,7,8,9,10 };

	cout << BinarySearchRecursive(TAB, 9, 0, 10) << endl;
	cout << ExecutionCounter << endl;

	vector <int> TAB_BIG;

	const int BigTabSize = 1000;
	TAB_BIG.reserve(BigTabSize);

	for (int i = 0; i < 1000; i++)
	{
		TAB_BIG.push_back(i);
	}

	ExecutionCounter = 0;
	
	cout << BinarySearchRecursive(TAB_BIG, 666, 0, BigTabSize) << endl;

	cout << ExecutionCounter;

	ExecutionCounter = 0;

	cout << BinarySearch(TAB_BIG, 896) << endl;

	cout << ExecutionCounter;


	return 0;
}
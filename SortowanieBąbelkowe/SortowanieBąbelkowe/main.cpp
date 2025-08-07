#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

void BubbleSort(vector<int>& tab)
{
	bool wasSwapped = false;
	
	for (int j = 0; j < tab.size(); ++j)
	{
		for (int i = 0; i < tab.size() - 1; ++i)
		{
			if (tab[i] > tab[i + 1])
			{
				swap(tab[i], tab[i + 1]);
				wasSwapped = true;
			}
		}
	}

	if (!wasSwapped) return;
	
	
}

int main()
{
	vector <int> TAB = { 5,9,8,47,89,34,27,35,12,54 };
	BubbleSort(TAB);


	
	
	return 0;

}
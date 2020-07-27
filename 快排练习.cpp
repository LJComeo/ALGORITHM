#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &v, int left, int right)
{
	if (left < right)
	{
		int a = left, b = right, key = v[a];
		while (a < b)
		{
			while (a < b && v[b] >= key)
				b--;
			if (a < b)
			{
				v[a++] = v[b];
			}
			while (a < b && v[a] < key)
				a++;
			if (a < b)
			{
				v[b--] = v[a];
			}
		}
		v[a] = key;
		QuickSort(v, left, a - 1);
		QuickSort(v, a + 1, right);
	}
}


int main()
{
	vector<int> v{ 3, 5, 2, 7, 1, 9 };
	QuickSort(v, 0, v.size() - 1);
	for (auto &i : v)
	{
		cout << i << ' ';
	}
	cout << endl;

	return 0;
}
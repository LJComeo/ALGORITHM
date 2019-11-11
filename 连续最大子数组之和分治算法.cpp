#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dealGreatestSum(vector<int> &array, int begin, int end)
{
	if (begin == end)
	{
		return array[begin];
	}
	int mid = (begin + end) / 2;
	int leftmax = dealGreatestSum(array, begin, mid);
	int rightmax = dealGreatestSum(array, mid + 1, end);
	int crossmax = 0;
	int i;
	int sum = 0;
	int tmpmax = array[mid];
	for (i = mid; i >= begin; i--)
	{
		sum += array[i];
		if (sum > tmpmax)
		{
			tmpmax = sum;
		}
	}
	crossmax += tmpmax;

	sum = 0;
	tmpmax = array[mid + 1];
	for (i = mid + 1; i <= end; i++)
	{
		sum += array[i];
		if (sum > tmpmax)
		{
			tmpmax = sum;
		}
	}
	crossmax += tmpmax;
	return max(max(leftmax, rightmax), crossmax);


}

int FindFreatestSumOfSubArray(vector<int> array)
{
	return dealGreatestSum(array, 0, array.size() - 1);
}

int main()
{




}
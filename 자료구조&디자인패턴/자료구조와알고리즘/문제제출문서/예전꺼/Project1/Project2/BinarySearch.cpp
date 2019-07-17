#include <iostream>
using namespace std;

int BSearch(int arr[], int first, int last, int target)
{
	if (first > last) return -1;

	int mid;
	mid = (first + last) / 2;

	if (target == arr[mid])
	{
		return mid;  
	}
	else
	{
		if (target < arr[mid])
			last = mid - 1;
		else
			first = mid + 1;
		BSearch(arr, first, last, target);
	}
}

int BSearchInit(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int targetindex;

	targetindex = BSearch(arr, first, last, target);

	return targetindex;
}

int main()
{
	int arr[] = { 1, 3, 4, 5, 7, 9 ,10};
	int idx;

	idx = BSearchInit(arr, sizeof(arr) / sizeof(int), 7);

	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ" << endl;
	else
		cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º : " << idx << endl;

	idx = BSearchInit(arr, sizeof(arr) / sizeof(int), 4);

	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ" << endl;
	else
		cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º : " << idx << endl;

	return 0;
}
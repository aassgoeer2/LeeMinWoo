#include <iostream>
using namespace std;

int Fibo(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
	int* arr;
	int size = 0;

	cout << "ют╥б: ";
	cin >> size;

	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = Fibo(i);

		cout << arr[i] << " ";
	}

	delete[] arr;

	return 0;
}
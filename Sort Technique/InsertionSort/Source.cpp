#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i], j;
		for (j = i - 1; j >= 0 && temp < a[j]; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}		
}

int main()
{
	int a[10001];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	//Sorting
	InsertionSort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
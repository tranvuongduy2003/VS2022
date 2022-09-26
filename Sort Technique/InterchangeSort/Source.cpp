#include <iostream>
using namespace std;

void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[j], a[i]);
}

int main()
{
	int a[10001];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	//Sorting
	InterchangeSort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
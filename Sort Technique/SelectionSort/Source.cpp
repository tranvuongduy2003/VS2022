#include <iostream>
using namespace std;

void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n + 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
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
	SelectionSort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
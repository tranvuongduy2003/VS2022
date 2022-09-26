#include <iostream>
using namespace std;

void QuickSort(int a[], int l, int r)
{
	int i, j, m;
	i = l;
	j = r;
	m = (i + j) / 2;
	while (i < j)
	{
		while (a[i] < a[m]) i++;
		while (a[j] > a[m]) j--;
		if (i < j)
			swap(a[i], a[j]);
		i++; j--;
	}

	if (i < r) QuickSort(a, i, r);
	if (l < j) QuickSort(a, l, j);
}

int main()
{
	int a[10001];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	//Sorting
	QuickSort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
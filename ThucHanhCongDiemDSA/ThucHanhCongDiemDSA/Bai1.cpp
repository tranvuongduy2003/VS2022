#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void QuickSort(int* a, int l, int r)
{
	int i, j, m, t;
	i = l;
	j = r;
	m = (l + r) / 2;
	while (i <= j)
	{
		while (a[i] < a[m]) i++;
		while (a[j] > a[m]) j--;
		if (i <= j)
		{
			if (i < j)
			{
				t = a[i]; a[i] = a[j]; a[j] = t;
			}
			i++; j--;
		}
	}

	if (l < j) QuickSort(a, l, j);
	if (i < r) QuickSort(a, i, r);
}

void Generate(int a[], int& m, int n)
{
	vector<bool> f(n + 1, 1);
	for (int i = 2; i <= sqrt(n); i++)
		if (f[i] == 1)
			for (int j = i + i; j <= n; j += i)
				f[j] = 0;
	for (int i = 2; i <= sqrt(n); i++)
		for (int j = i * i; j <= n; j *= i)
			f[j] = 1;
	int i = 1, t;
	for (int j = 2; j <= n; t = j, j = j + i, i = t)
		f[j] = 1;

	m = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] == 1)
			a[m++] = i;
}

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main()
{
	int n, m;
	cin >> n;
	int* a = new int[n];
	Generate(a, m, n);
	QuickSort(a, 0, m - 1);
	Print(a, m);
	delete[]a;
	return 0;
}
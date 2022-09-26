#include <iostream>
using namespace std;

void ShellSort(int a[], int n, int h[], int k)
{
	for (int step = 0; step < k; step++)
	{
		int len = h[step];
		for (int i = len; i < n; i++)
		{
			int temp = a[i];
			int j;
			for (j = i - len; j >= 0 && temp < a[j]; j -= len)
				a[j + len] = a[j];
			a[j + len] = temp;
		}
	}
}

int main()
{
	int a[10001];
	int h[5] = { 1, 4, 13, 40, 121 };
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	//Sorting
	ShellSort(a, n, h, 5);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
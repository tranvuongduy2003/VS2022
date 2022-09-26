#include <iostream>
using namespace std;

void Copy(int a[], int b[], int l, int r, int& n)
{
	n = 0; 
	for (int i = l; i <= r; i++)
		b[n++] = a[i];
}

void Merge(int a[], int l, int m, int r)
{
	int* b = new int[m - l + 1];
	int* c = new int[r - m];
	int nc, nb;

	Copy(a, b, l, m, nb);
	Copy(a, c, m + 1, r, nc);

	int i = 0, j = 0, t = l;
	while (i < nb && j < nc)
	{
		if (b[i] < c[j])
			a[t++] = b[i++];
		else
			a[t++] = c[j++];
	}
	while (i < nb) a[t++] = b[i++];
	while (j < nc) a[t++] = c[j++];

	delete[] b;
	delete[] c;
}

void MergeSort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	MergeSort(a, l, m);
	MergeSort(a, m + 1, r);
	Merge(a, l, m, r);
}

int main()
{
	int a[10001];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	//Sorting
	MergeSort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
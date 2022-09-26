#include <iostream>
using namespace std;

void Heapify(int a[], int n, int i)
{
	int l = i * 2;
	int r = i * 2 + 1;
	int largest = i;

	if (l < n && a[l] > a[largest])
		largest = l;

	if (l < n && a[r] > a[largest])
		largest = r;

	if (largest != i)
	{
		swap(a[largest], a[i]);
		Heapify(a, n, largest);
	}
}

void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		Heapify(a, n, 0);
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
	HeapSort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
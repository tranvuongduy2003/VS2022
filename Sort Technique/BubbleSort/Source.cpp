#include <iostream>
using namespace std;

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n; j > i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
//Cai tien bang cach cho ShakerSort

int main()
{
	int a[10001];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	//Sorting
	BubbleSort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
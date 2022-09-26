#include <iostream>
using namespace std;

int main()
{
	int n, tempChild;
	cin >> n;
	Template** temp = new Template * [n];
	for (int i = 0; i < n; i++)
	{
		cin >> tempChild;
		cin.ignore();
		if (tempChild == 1)
			temp[i] = new Child1;
		if (tempChild == 2)
			temp[i] = new Child2;
		if (tempChild == 3)
			temp[i] = new Child3;
		temp[i]->Nhap();
	}

	for (int i = 0; i < n; i++)
		temp[i]->Xuat();

	delete[] temp;

	return 0;
}
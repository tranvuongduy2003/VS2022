#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, option;
	cin >> n;
	Object** object = new Object * [n];
	for (int i = 0; i < n; i++)
	{
		cin >> option;
		cin.ignore();
		if (option == 1)
			object[i] = new Obj1;
		if (option == 2)
			object[i] = new Obj2;
		if (option == 3)
			object[i] = new Obj3;
		object[i]->Nhap();
	}

	for (int i = 0; i < n; i++)
		object[i]->Xuat();

	delete[] object;

	return 0;
}
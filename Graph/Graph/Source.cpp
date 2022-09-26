#include <iostream>
#include <vector>
#include "List.h"
using namespace std;


int main()
{
	List l[101];
	int f[101][101];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> f[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (f[i][j] == 1)
				l[i].push_back(j);
			
	for (int i = 1; i <= n; i++)
	{
		cout << i << " : ";
		l[i].print();
		cout << endl;
	}

	return 0;
}
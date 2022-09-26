#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> tsp;
bool visited[1001];
int route[1001];

void Nhap()
{
	//cin >> n >> m;
	/*for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		tsp[x][y] = w;
	}*/
	n = 4;
	tsp = { { 0,  0,  0,  0,  0 },
			{ 0, -1, 10, 15, 20 },
			{ 0, 10, -1, 35, 25 },
            { 0, 15, 35, -1, 30 },
            { 0, 20, 25, 30, -1 } };
	memset(visited, false, sizeof(visited));
}

void FindMinRoad()
{
	int sum = 0;
	int counter = 0;
	int i = 1, j = 1;
	int min = INT_MAX;

	visited[1] = true;
	route[counter++] = 1;

	while (i <= n && j <= n)
	{
		if (counter >= n)
			break;

		if (j != i && visited[j] == false)
		{
			if (tsp[i][j] < min)
			{
				min = tsp[i][j];
				route[counter] = j;	
			}
		}
		j++;

		if (j == n + 1)
		{
			sum += min;
			min = INT_MAX;
			j = 1;
			i = route[counter];
			visited[i] = true;
			counter++;
		}
	}

	for (j = 1; j <= n; j++)
	{
		if ((i != j) && tsp[i][j] < min)
		{
			min = tsp[i][j];
			route[counter] = j;
		}
	}
	sum += min;

	for (int i = 0; i <= counter; i++)
		cout << route[i] << " ";
	cout << endl;
	cout << sum << endl;
}

int main()
{
	Nhap();
	FindMinRoad();
	return 0;
}
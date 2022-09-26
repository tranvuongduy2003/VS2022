#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1001;

struct canh
{
	int x, y, w;
};

int n, m;
vector<pair<int, int>> adj[maxn];
bool used[maxn];

void Nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({ y, w });
		adj[y].push_back({ x, w });
	}
	memset(used, false, sizeof(used));
}

void Prim()
{
	vector<canh> MST;
	int d = 0;
	used[u] = true;
	while (MST.size() < n - 1)
	{
		int min_w = INT_MAX;
		int X, Y;
		for (int i = 1; i <= n; i++)
		{
			if (used[i])
			{
				for (pair<int, int> it : adj[i])
				{
					int j = it.first, trongso = it.second;
					if (!used[u] && trongso < min_w)
					{
						min_w = trongso;
						X = j; Y = i;
					}

				}
			}
		}
		MST.push_back({ X, Y, min_w });
		d += min_w;
		used[X] = true;
	}
	cout << d << endl;
	for (canh e : MST)
		cout << e.x << " " << e.y << " " << e.w << endl;
}

int main()
{
	Nhap();
	Prim(1);
	return 0;
}
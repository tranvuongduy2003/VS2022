#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using ll = long long;


const int INF = 1e9;
const int maxn = 100001;
int n, m, s;
vector<pair<int, int>> adj[maxn];

void Nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({ y, w });
		//vo huong
		adj[y].push_back({ x, w });
	}
}

void Dijkstra(int s)
{
	//Mang luu khoang cach duong di
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({ 0, s });
	while (!Q.empty())
	{
		pair<int, int> top = Q.top(); Q.pop();
		int kc = top.first;
		int u = top.second;
		if (kc > d[u]) continue;
		for (auto it : adj[u])
		{
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				Q.push({ d[v], v });
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << d[i] << " ";
	}
}

int main()
{
	Nhap();
	Dijkstra(1);
	return 0;
}
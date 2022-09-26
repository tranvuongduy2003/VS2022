#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void inp()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void bfs(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		cout << top << " ";
		for (int v : adj[top])
			if (!visited[v])
			{
				q.push(v);
				visited[v] = true;
			}
	}
}

int main()
{ 
	inp();
	bfs(1);
	return 0;
}
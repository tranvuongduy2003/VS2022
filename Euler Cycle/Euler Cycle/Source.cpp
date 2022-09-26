#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

using ll = long long;

int n, m;
set<int> adj[1001];
int degree[1001];

void Nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
		degree[x]++;
		degree[y]++;
	}
}

void EulerCycle(int v)
{
	stack<int> st;
	vector<int> EC;
	st.push(v);
	while (!st.empty())
	{
		int x = st.top();
		if (adj[x].size() != 0)
		{
			int y = *adj[x].begin();
			st.push(y);
			adj[x].erase(y);
			adj[y].erase(x);
		}
		else
		{
			st.pop();
			EC.push_back(x);
		}
	}
	reverse(EC.begin(), EC.end());
	for (int x : EC) cout << x << " ";
}

int main()
{
	Nhap();
	EulerCycle(1);
	return 0;
}
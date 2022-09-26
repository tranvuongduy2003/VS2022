#include <iostream>
#include <map>
using namespace std;

int e;
map<string, vector<string>> adj;
map<string, bool> visited;

void Nhap()
{
	cin >> e;
	for (int i = 0; i < e; i++)
	{
		string x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		visited[x] = visited[y] = false;
	}
}

void ToMau()
{
	auto& itemp = adj.begin();
	for (auto it = adj.begin(); it != adj.end(); it++)
		if (it->second.size() > itemp->second.size())
			itemp = it;

}

int main()
{
	Nhap();
	ToMau();
	return 0;
}
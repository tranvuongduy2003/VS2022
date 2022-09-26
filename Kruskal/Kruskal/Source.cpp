#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

struct Edge
{
	int u, v, w;
};

const int maxn = 10001;
int n, m;
int parent[maxn], sz[maxn];
vector<Edge> canh;


void MakeSet()
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}
}

int Find(int v)
{
	if (v == parent[v]) return v;
	return parent[v] = Find(parent[v]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	//sz[a] + sz[b];
	return true;
}

void Nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		Edge e = Edge({ x, y, w });
		canh.push_back(e);
	}
}

bool Cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

void Kruskal()
{
	vector<Edge> mst;
	int d = 0;
	sort(canh.begin(), canh.end(), Cmp);
	for (int i = 0; i < m; i++)
	{
		if (mst.size() == n - 1) break;
		Edge e = canh[i];
		if (Union(e.u, e.v))
		{
			mst.push_back(e);
			d += e.w;
		}
	}
		
	if (mst.size() != n - 1)
		cout << "Do thi khong lien thong!\n";
	else
	{
		cout << "MST : " << d << endl;
		for (auto it : mst)
			cout << it.u << " " << it.v << " " << it.w << endl;
	}
}


int main()
{
	Nhap();
	MakeSet();
	Kruskal();
	return 0;
}
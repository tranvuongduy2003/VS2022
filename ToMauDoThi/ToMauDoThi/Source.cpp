#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int e;
struct Node
{
	string data;
	vector <string> adj;
	void push(string name) { adj.push_back(name); }
};
struct Graph
{
	vector <Node> dinh;
	Node& operator [] (string name) {
		bool flag = false;
		for (auto it = dinh.begin(); it != dinh.end(); it++)
			if (it->data == name)
			{
				flag = true;
				return *it;
			}
		if (!flag)
		{
			Node temp;
			temp.data = name;
			dinh.push_back(temp);
			return dinh.back();
		}
	};
} graph;
struct Visited
{
	vector <pair<string, bool>> dinh;
	auto& operator [] (string name) {
		bool flag = false;
		for (auto it = dinh.begin(); it != dinh.end(); it++)
			if (it->first == name)
			{
				flag = true;
				return *it;
			}
		if (!flag)
		{
			pair<string, bool> temp;
			temp.first = name;
			dinh.push_back(temp);
			return dinh.back();
		}
	};
} visited;

void Nhap()
{
	cin >> e;
	for (int i = 0; i < e; i++)
	{
		string x, y;
		cin >> x >> y;
		graph[x].push(y);
		graph[y].push(x);
		visited[x].second = visited[y].second = false;
	}
}

bool cmp(Node& a, Node& b)
{
	return a.adj.size() > b.adj.size();
}

int ToMau()
{
	int count = 0;
	sort(graph.dinh.begin(), graph.dinh.end(), cmp);
	for (auto it = graph.dinh.begin(); it != graph.dinh.end(); it++)
	{
		if (visited[it->data].second == false)
		{
			for (auto it2 = it + 1; it2 != graph.dinh.end(); it2++)
			{
				auto temp = find(it2->adj.begin(), it2->adj.end(), it->data);
				if (temp == it2->adj.end())
					visited[it2->data].second = true;
			}
			count++;
		}
		visited[it->data].second = true;
	}

	return count;
}

void Xuat()
{
	for (auto it = graph.dinh.begin(); it != graph.dinh.end(); it++)
	{
		cout << it->data << " : ";
		for (auto it2 = it->adj.begin(); it2 != it->adj.end(); it2++)
			cout << *it2 << " ";
		cout << endl;
	}
}

int main()
{
	Nhap();
	cout << ToMau() << endl;
	Xuat();
	return 0;
}
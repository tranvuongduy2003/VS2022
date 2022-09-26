#include <iostream>
#include "Node.h"
using namespace std;

int Hash(int key)
{
	return key % 10;
}

void Insert(Node* HT[], int key)
{
	int index = Hash(key);
	InsertNode(HT[index], key);
}

int Search(Node* HT[], int key)
{
	int index = Hash(key);
	return SearchNode(HT[index], key);
}


int main()
{
	Node* HT[10];
	int i;
	for (int i = 0; i < 10; i++)
		HT[i] = nullptr;

	return 0;
}
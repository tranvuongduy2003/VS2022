#include <iostream>
using namespace std;

#pragma once
#ifndef List_h
#define List_h

struct Node
{
	int data;
	Node* next;
};

Node* InitNode(int x)
{
	Node* p = new Node;
	if (p == nullptr)
		return nullptr;
	p->data = x;
	p->next = nullptr;
	return p;
}

class List
{
public:
	Node* head = nullptr;
	Node* tail = nullptr;
	void push_back(int x)
	{
		Node* p = InitNode(x);
		if (head == nullptr)
			head = tail = p;
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	void print()
	{
		Node* p = head;
		while (p != nullptr)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
};


#endif // !List_h

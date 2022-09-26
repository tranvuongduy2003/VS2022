#pragma once
#ifndef Node_h
#define Node_h
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

void InsertNode(Node*& head, int key)
{
	Node* p = InitNode(key);
	if (head == nullptr)
		head = p;
	else
	{
		Node* q = head;
		while (q->next != nullptr)
			q = q->next;
		q->next = p;
	}
}

int SearchNode(Node* head, int key)
{
	while (head != nullptr)
	{
		if (head->data == key)
			return key;
	}
	return -1;
}
#endif

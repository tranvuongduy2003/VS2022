#pragma once
#ifndef Node_h
#define Node_h

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* InitNode(int x)
{
	Node* p = new Node;
	if (p == nullptr)
		return nullptr;
	p->data = x;
	p->left = nullptr;
	p->right = nullptr;
	return p;
}
#endif // !Node_h

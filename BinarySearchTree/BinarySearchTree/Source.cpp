#include <iostream>
#include "Node.h"
using namespace std;

struct Tree
{
	Node* root;
};

void InitTree(Tree&);
void Insert(Tree&, Node*);
int CountNode(Node*);
void PrintLNR(Node);
int Height(Node*);
void RemoveAll(Tree&);
Node* Max(Tree);
Node* Min(Tree);
void Reverse(Node*&);
int CountSingleLeafNode(Node*);
Node* InPre(Node*);
Node* InSucc(Node*);
Node* Delete(Tree&, Node*&, int);

int main()
{
	return 0;
}

void InitTree(Tree& t)
{
	t.root = nullptr;
}
void Insert(Tree& t, Node* p)
{
	Node* q = t.root;
	Node* s = nullptr;
	while (q != nullptr)
	{
		s = q;
		if (q->data < p->data)
			q = q->left;
		else if (q->data > p->data)
			q = q->right;
		else
			return;
	}
	if (p->data < s->data)
		s->left = p;
	else
		s->right = p;
}
int CountNode(Node* root)
{
	if (root == nullptr)
		return 0;
	int a = CountNode(root->left);
	int b = CountNode(root->right);
	return a + b + 1;
}
void PrintLNR(Node* root)
{
	if (root == nullptr)
		return;
	PrintLNR(root->left);
	cout << root->data << " ";
	PrintLNR(root->right);
}
int Height(Node* root)
{
	if (root == nullptr)
		return 0;
	int a = Height(root->left);
	int b = Height(root->right);
	if (a < b)
		return b + 1;
	return a + 1;
}
void RemoveAll(Node*& root)
{
	if (root == nullptr)
		return;
	RemoveAll(root->left);
	RemoveAll(root->right);
	delete root;
}
Node* Max(Tree t)
{
	Node* p;
	p = t.root;
	while (p->right != nullptr)
		p = p->right;
	return p;
}
Node* Min(Tree t)
{
	Node* p;
	p = t.root;
	while (p->left != nullptr)
		p = p->left;
	return p;
}
void Reverse(Node*& root)
{
	if (root == nullptr)
		return;
	Reverse(root->left);
	Reverse(root->right);
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}
int CountSingleLeafNode(Node* root)
{
	if (root == nullptr)
		return 0;
	int a = CountSingleLeafNode(root->left);
	int b = CountSingleLeafNode(root->right);
	if (root->left != nullptr ^ root->right != nullptr)
		return a + b + 1;
	return a + b;
}
Node* InPre(Node* p)
{
	while (p && p->right != nullptr)
		p = p->right;
	return p;
}
Node* InSucc(Node* p)
{
	while (p && p->left != nullptr)
		p = p->left;
	return p;
}
Node* Delete(Tree& t, Node*& p, int key)
{
	if (p == nullptr)
		return nullptr;
	if (p->left == nullptr && p->right == nullptr)
	{
		if (p == t.root)
			t.root = nullptr;
		delete(p);
		return nullptr;
	}

	if (key < p->data)
		p->left = Delete(t, p->left, key);
	else if (key > p->data)
		p->right = Delete(t, p->right, key);
	else
	{
		Node* q = nullptr;
		if (Height(p->left) > Height(p->right))
		{
			q = InPre(p->left);
			p->data = q->data;
			p->left = Delete(t, p->left, q->data);
		}
		else
		{
			q = InSucc(p->right);
			p->data = q->data;
			p->right = Delete(t, p->right, q->data);
		}
	}
	return p;
}
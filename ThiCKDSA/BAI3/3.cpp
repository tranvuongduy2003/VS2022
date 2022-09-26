#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

struct Tree
{
	Node* root;
};

Node* InitNode(int);
void InitTree(Tree&);
Node* Search(Node*, int);
Node* DeepestNode(Tree);
void RemoveNode(Tree&, int);
void PrintAToB(Tree, int, int);
int SumOfSingleLeafNode(Node*);
int SumOfFullLeafNode(Node*);


int main()
{
	return 0;
}

Node* InitNode(int x)
{
	Node* p = new Node;
	if (p == nullptr)
		return nullptr;
	p->data = x;
	p->left = p->right = nullptr;
}
void InitTree(Tree& t)
{ 
	t.root = nullptr;
}
Node* Search(Node* root, int key) 
{
	if (root == nullptr)
		return nullptr;
	if (root->data == key)
		return root;
	return Search(root->left, key) ? Search(root->left, key) : Search(root->right, key);
}
Node* DeepestNode(Tree t)
{
	queue<Node*> q;
	Node* p = nullptr;
	q.push(t.root);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (p->left != nullptr)
			q.push(p->left);
		if (p->right != nullptr)
			q.push(p->right);
	}
	return p;
}
void RemoveNode(Tree& t, int key)
{
	Node* p = Search(t.root, key);
	Node* q = DeepestNode(t);
	if (p == nullptr)
	{
		cout << key << "doesn't exist" << endl;
		return;
	}
	if (p == q)
		delete p;
	else
	{
		int temp = p->data;
		p->data = q->data;
		q->data = temp;
		delete q;
	}
}
void PrintAToB(Tree t, int a, int b)
{
	queue<Node*> q;
	Node* p = nullptr;
	q.push(t.root);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (p->data >= a && p->data <= b)
			cout << p->data << " ";
		if (p->left != nullptr)
			q.push(p->left);
		if (p->right != nullptr)
			q.push(p->right);
	}
}
int SumOfSingleLeafNode(Node* root)
{
	if (root == nullptr)
		return 0;
	int a = SumOfSingleLeafNode(root->left);
	int b = SumOfSingleLeafNode(root->right);
	if (root->left != nullptr ^ root->right != nullptr)
		return a + b + root->data;
	return a + b;
}
int SumOfFullLeafNode(Node* root)
{
	if (root == nullptr)
		return 0;
	int a = SumOfFullLeafNode(root->left);
	int b = SumOfFullLeafNode(root->right);
	if (root->left != nullptr && root->right != nullptr)
		return a + b + root->data;
	return a + b;
}
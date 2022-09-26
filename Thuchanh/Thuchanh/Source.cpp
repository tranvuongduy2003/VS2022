#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
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

void InitList(List& l)
{
	l.head = l.tail = nullptr;
}

void InsertHead(List& l, int x)
{
	Node* p = InitNode(x);
	if (p == nullptr)
		return;
	if (l.head == nullptr)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}	

int Length(List l)
{
	int s = 0;
	Node* p = l.head;
	while (p != nullptr)
	{
		s++;
		p = p->next;
	}
}

void ConvertBigNumToList(List& l, string s)
{
	for (int i = 0; i < s.length(); i++)
		InsertHead(l, s[i] - 48);
}

List Sum(List a, List b)
{
	int lengthA = sizeof(a) / sizeof(Node*);
	int lengthB = sizeof(b) / sizeof(Node*);

	Node* p = a.head;
	Node* q = b.head;
	int mod = 0, div = 0;
	List l;
	InitList(l);
	while (p != nullptr && q != nullptr)
	{
		mod = (p->data + q->data + div) % 10;
		div = (p->data + q->data + div) / 10;
		InsertHead(l, mod);
		p = p->next;
		q = q->next;
	}

	while (p != nullptr)
	{
		mod = (p->data + div) % 10;
		div = (p->data + div) / 10;
		InsertHead(l, mod);
		p = p->next;
	}

	while (q != nullptr)
	{
		mod = (q->data + div) % 10;
		div = (q->data + div) / 10;
		InsertHead(l, mod);
		q = q->next;
	}

	if (div != 0)
		InsertHead(l, div);

	return l;
}

List Subtract(List a, List b)
{
	Node* p = a.head;
	Node* q = b.head;
	int mod = 0, div = 0;
	List l;
	InitList(l);
	while (p != nullptr && q != nullptr)
	{
		mod = (p->data + q->data + div) % 10;
		div = (p->data + q->data + div) / 10;
		InsertHead(l, mod);
		p = p->next;
		q = q->next;
	}

	while (p != nullptr)
	{
		mod = (p->data + div) % 10;
		div = (p->data + div) / 10;
		InsertHead(l, mod);
		p = p->next;
	}

	while (q != nullptr)
	{
		mod = (q->data + div) % 10;
		div = (q->data + div) / 10;
		InsertHead(l, mod);
		q = q->next;
	}

	if (div != 0)
		InsertHead(l, div);

	return l;
}

void PrintList(List l)
{
	Node *p = l.head;
	while (p != nullptr)
	{
		cout << p->data;
		p = p->next;
	}
}

int main()
{
	List l1, l2, l3;
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	InitList(l1);
	l1.head = InitNode(1);
	l1.head->next = InitNode(1);
	 = InitNode(1);
	cout << sizeof(l1) / sizeof(Node) << endl;
	InitList(l2);
	InitList(l3);
	ConvertBigNumToList(l1, s1);
	ConvertBigNumToList(l2, s2);
	l3 = Sum(l1, l2);
	PrintList(l3);
	return 0;
}
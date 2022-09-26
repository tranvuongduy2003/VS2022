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

void Insert(List& l, int x)
{
	Node* p = InitNode(x);
	if (l.head == nullptr)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
 	}
}

void InsertTail(List& l, int x)
{
	Node* p = InitNode(x);
	if (l.head == nullptr)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
 	}
}

int Length(List l)
{
	Node* p = l.head;
	int length = 0;
	while (p != nullptr)
	{
		p = p->next;
		length++;
	}
	return length;
}

List ConvertToList(string s)
{
	List l;
	InitList(l);
	for (int i = 0; i < s.length(); i++)
		Insert(l, s[i] - 48);
	return l;
}

void FillZero(List& l, int len)
{
	for (int i = 0; i < len; i++)
		InsertTail(l, 0);
}

void RemoveZero(List& l)
{
	Node* p = l.head;
	while (p->next != nullptr || p->data != 0)
	{
		p = p->next;
		l.head = p;
	}
}

List Add(List l1, List l2)
{
	List l;
	int nho = 0;
	InitList(l);
	
	Node* p = l1.head;
	Node* q = l2.head;
	while (p != nullptr)
	{
		int temp = p->data + q->data + nho;
		if (temp >= 10)
		{
			InsertTail(l, temp % 10);
			nho = 1;
		}
		else
		{
			InsertTail(l, temp);
			nho = 0;
		}
		p = p->next; q = q->next;
	}
	return l;
}

List Sub(List l1, List l2)
{
	List l;
	int nho = 0;
	InitList(l);
	Node* p = l1.head;
	Node* q = l2.head;
	while (p != nullptr)
	{
		int temp = p->data - q->data - nho;
		if (temp < 0)
		{
			Insert(l, temp + 10);
			nho = 1;
		}
		else
		{
			Insert(l, temp);
			nho = 0;
		}
		p = p->next; q = q->next;
	}
	RemoveZero(l);
	return l;
}

void ReversePrint(Node* head)
{
	if (head == nullptr)
		return;
	ReversePrint(head->next);
	cout << head->data;
}

void Print(Node* head)
{
	while (head != nullptr)
	{
		cout << head->data;
		head = head->next;
	}
}

List Mul(List l1, List l2)
{
	List l, t;
	int nho = 0, qzero = 0;
	InitList(l);
	Node* p = l1.head;
	while (p != nullptr)
	{
		Node* q = l2.head;
		InitList(t);
		while (q != nullptr)
		{
			int temp = q->data * p->data + nho;
			InsertTail(t, temp % 10);
			nho = temp / 10;
			q = q->next;
		}
		for (int i = 0; i < qzero; i++)
			Insert(t, 0);
		FillZero(l, Length(t) - Length(l));
		l = Add(t, l);
		qzero++;
		p = p->next;
	}
	return l;
}



int main()
{
	List l1, l2;
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);

	l1 = ConvertToList(s1);
	l2 = ConvertToList(s2);

	List tong, hieu, tich, thuong;


	cout << "Tong: ";
	if (s1.compare(s2) > 0)
	{
		FillZero(l2, s1.length() - s2.length());
		tong = Add(l1, l2);
	}
	else
	{
		FillZero(l1, s2.length() - s1.length());
		tong = Add(l2, l1);
	}
	ReversePrint(tong.head);

	cout << "\nHieu: ";
	if (s1.compare(s2) >= 0)
	{
		FillZero(l2, s1.length() - s2.length());
		hieu = Sub(l1, l2);
	}
	else
	{
		FillZero(l1, s2.length() - s1.length());
		hieu = Sub(l2, l1);
		cout << "-";
	}
	Print(hieu.head);

	cout << "\nTich: ";
	tich = Mul(l1, l2);
	ReversePrint(tich.head);

	return 0;
}
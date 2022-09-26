#include <iostream>
#include <queue>
using namespace std;

struct Date
{
	int ngay;
	int thang;
	int nam;
};

struct DocGia
{
	char ma[5];
	char ten[30];
	char diaChi[30];
	Date ngayLap;
};

struct Node
{
	DocGia data;
	Node* left;
	Node* right;
};

struct Tree
{
	Node* root;
};

Node* InitNode(int x)
{
	Node* p = new Node;
	DocGia dg;
	if (p == nullptr)
		return nullptr;
	p->data = dg;
	p->left = p->right = nullptr;
}
void InitTree(Tree& t)
{
	t.root = nullptr;
}
Node* TimNgaySomNhat(Node* root, int key)
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

//void PrintDate(Date d)
//{
//	cout << d.ngay << "/" << d.thang << "/" << d.nam;
//}
//void Print(List l)
//{
//	cout << setw(15) << "MSSV";
//	cout << setw(30) << "HO VA TEN";
//	cout << setw(12) << "NGAY SINH";
//	cout << setw(20) << "DIEM THI";
//	cout << endl;
//	Node* p = l.head;
//	while (p != nullptr)
//	{
//		cout << setw(15) << p->info.mssv;
//		cout << setw(30) << p->info.hoTen;
//		cout << setw(12);
//		PrintDate(p->info.ngaySinh);
//		cout << setw(20) << p->info.diemThi;
//		cout << endl;
//		p = p->next;
//	}
//}


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

int main()
{

	return 0;
}
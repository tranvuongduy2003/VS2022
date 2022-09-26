#include <iostream>
#include <queue>
#include <string.h>
#include <iomanip>
using namespace std;

struct Date
{
	int ngay;
	int thang;
	int nam;
	bool operator > (const Date& d)
	{
		if (nam > d.nam)
			return true;
		else if (nam == d.nam && thang > d.thang)
			return true;
		else if (nam == d.nam && thang == d.thang && ngay > d.ngay)
			return true;
		else
			return false;
	}
	bool operator > (int nam)
	{
		return this->nam > nam;
	}
	bool operator == (Date d)
	{
		return (nam == d.nam && thang == d.thang && ngay == d.ngay);
	}
};

struct DocGia
{
	char ma[5];
	char ten[30];
	char diaChi[30];
	Date ngayLap;
	bool operator > (const DocGia& dg)
	{
		return strcmp(ma, dg.ma) > 0;
	}
	bool operator < (const DocGia& dg)
	{
		return strcmp(ma, dg.ma) < 0;
	}
	bool operator == (char* ma)
	{
		return strcmp(this->ma, ma) == 0;
	}
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

Node* InitNode(DocGia);
void InitTree(Tree&);
void ReadReader(DocGia&);
void CreateTree(Tree&, int n);
void Insert(Tree&, DocGia);
char* Oldest(Tree&);
void ReadersAfter2000(Tree);
int ValidReaders(Tree);
void ReadersIdX(Tree, char*);
void PrintDate(Date);
void PrintNode(Node*);
void PrintHeader();
void PrintTree(Node*);


int main()
{
	int n, sl;
	char ma[5]{};
	Tree t;
	InitTree(t);
	
	cout << "Nhap so luong doc gia: ";
	cin >> n;
	cin.ignore();
	CreateTree(t, n);

	cout << "Ma doc gia lon tuoi nhat: " << Oldest << endl;

	ReadersAfter2000(t);

	sl = ValidReaders(t);
	cout << "So luong doc gia co ngay lap the trong ngay 26/05/2022: " << sl << endl;

	cin.getline(ma, 5);
	ReadersIdX(t, ma);

	return 0;
}

Node* InitNode(DocGia dg)
{
	Node* p = new Node;
	if (p == nullptr)
		return nullptr;
	p->data = dg;
	p->left = p->right = nullptr;
	return p;
}
void InitTree(Tree& t)
{
	t.root = nullptr;
}
void ReadReader(DocGia& dg)
{
	cout << "Nhap ma doc gia: ";
	cin.getline(dg.ma, 5);
	cout << "Nhap ten doc gia: ";
	cin.getline(dg.ten, 30);
	cout << "Nhap dia chi: ";
	cin.getline(dg.diaChi, 30);
	cout << "Nhap ngay lap the: " << endl;
	cout << "Nhap ngay: ";
	cin >> dg.ngayLap.ngay;
	cout << "Nhap thang: ";
	cin >> dg.ngayLap.thang;
	cout << "Nhap nam: ";
	cin >> dg.ngayLap.nam;
	cin.ignore();
}
void CreateTree(Tree& t, int n)
{
	DocGia temp;
	for (int i = 0; i < n; i++)
	{
		ReadReader(temp);
		Insert(t, temp);
	}
}
void Insert(Tree& t, DocGia dg)
{
	Node* temp = InitNode(dg);
	if (temp == nullptr) return;
	if (t.root == nullptr)
	{
		t.root = temp;
		return;
	}
	Node* q = nullptr;
	Node* p = t.root;
	while (p != nullptr)
	{
		q = p;
		if (temp->data > p->data)
			p = p->right;
		else if (temp->data < p->data)
			p = p->left;
		else
			return;
	}
	if (temp->data < q->data)
		q->left = temp;
	else
		q->right = temp;
}

char* Oldest(Tree& t)
{
	queue<Node*> q;
	Node* p = nullptr;
	Node* res = t.root;
	q.push(t.root);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (p->data.ngayLap > res->data.ngayLap)
			res = p;
		if (p->left != nullptr)
			q.push(p->left);
		if (p->right != nullptr)
			q.push(p->right);
	}
	return res->data.ma;
}

void ReadersAfter2000(Tree t)
{
	PrintHeader();
	queue<Node*> q;
	Node* p = nullptr;
	q.push(t.root);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (p->data.ngayLap > 2000)
			PrintNode(p);
		if (p->left != nullptr)
			q.push(p->left);
		if (p->right != nullptr)
			q.push(p->right);
	}
}

int ValidReaders(Tree t)
{
	int s = 0;
	PrintHeader();
	queue<Node*> q;
	Node* p = nullptr;
	q.push(t.root);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (p->data.ngayLap == Date{ 26, 5, 2022 })
		{
			PrintNode(p);
			s++;
		}
		if (p->left != nullptr)
			q.push(p->left);
		if (p->right != nullptr)
			q.push(p->right);
	}
	return s;
}

void ReadersIdX(Tree t, char* ma)
{
	PrintHeader();
	queue<Node*> q;
	Node* p = nullptr;
	q.push(t.root);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (p->data == ma)
			PrintNode(p);
		if (p->left != nullptr)
			q.push(p->left);
		if (p->right != nullptr)
			q.push(p->right);
	}
}


void PrintDate(Date d)
{
	cout << d.ngay << "/" << d.thang << "/" << d.nam;
}
void PrintNode(Node* p)
{
	cout << setw(15) << p->data.ma;
	cout << setw(30) << p->data.ten;
	cout << setw(12);
	PrintDate(p->data.ngayLap);
	cout << setw(40) << p->data.diaChi;
	cout << endl;
}
void PrintHeader()
{
	cout << setw(15) << "MA DOC GIA";
	cout << setw(30) << "HO VA TEN";
	cout << setw(12) << "NGAY SINH";
	cout << setw(40) << "DIEM THI";
	cout << endl;
}
void PrintTree(Node* root)
{
	if (root == nullptr)
		return;
	PrintTree(root->left);
	PrintNode(root);
	PrintTree(root->right);
}
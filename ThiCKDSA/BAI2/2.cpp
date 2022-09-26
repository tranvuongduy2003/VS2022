#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Date
{
	int ngay;
	int thang;
	int nam;
};

struct SinhVien
{
	char mssv[10];
	string hoTen;
	float diemThi;
	Date ngaySinh;
};

struct Node
{
	SinhVien info;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};

Node* InitNode(SinhVien);
void InitList(List&);
void ReadDOB(Date&);
void ReadSV(SinhVien&);
void ReadData(List&, int);
void PrintDate(Date);
void Print(List);
int ThongKeGioi(List);
int ThongKeKha(List);
int ThongKeTB(List);
int ThongKeYeu(List);
void DeleteNode(List&, const char*);
void InsertNode(List&, Node*);
void ChuyenSinhVienDi(List&);
void ChuyenSinhVienVao(List&, int);
void SwapNode(Node*&, Node*&);
void BubbleSort(List&);


int main()
{
	int n, m;
	List SV;
	InitList(SV);

	cout << "=========== NHAP DANH SACH SINH VIEN ============" << endl;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	ReadData(SV, n);
	cout << "=========== IN DANH SACH SINH VIEN ============" << endl;
	Print(SV);

	cout << "=========== THONG KE XEP LOAI SINH VIEN ============" << endl;
	cout << "Gioi: " << ThongKeGioi(SV) << endl;
	cout << "Kha: " << ThongKeKha(SV) << endl;
	cout << "TB: " << ThongKeTB(SV) << endl;
	cout << "Yeu: " << ThongKeYeu(SV) << endl;

	cout << "=========== CHUYEN SINH VIEN DI ============" << endl;
	ChuyenSinhVienDi(SV);
	cout << "=========== DANH SACH SINH VIEN CON LAI ============" << endl;
	Print(SV);

	cout << "=========== CHUYEN SINH VIEN VAO ============" << endl;
	cout << "Nhap so luong sinh vien chuyen vao: ";
	cin >> m;
	ChuyenSinhVienVao(SV, m);

	cout << "=========== DANH SACH SINH VIEN MOI CAP NHAT ============" << endl;
	Print(SV);
	
	cout << "=========== SAP XEP DANH SACH SINH VIEN THEO DIEM ============" << endl;
	BubbleSort(SV);

	cout << "=========== DANH SACH SINH VIEN SAU KHI SAP XEP ============" << endl;
	Print(SV);

	return 0;
}

Node* InitNode(SinhVien sv)
{
	Node* p = new Node;
	if (p == nullptr)
		return nullptr;
	p->info = sv;
	p->next = nullptr;
	return p;
}
void InitList(List& l)
{
	l.head = l.tail = nullptr;
}
void ReadDOB(Date& d)
{
	cout << "Nhap ngay: ";
	cin >> d.ngay;
	cout << "Nhap thang: ";
	cin >> d.thang;
	cout << "Nhap nam: ";
	cin >> d.nam;
}
void ReadSV(SinhVien& sv)
{
	cout << "Nhap ma so sinh vien: ";
	cin.getline(sv.mssv, 10);
	cout << "Nhap ho va ten sinh vien: ";
	getline(cin, sv.hoTen);
	cout << "Nhap ngay sinh: " << endl;
	ReadDOB(sv.ngaySinh);
	cout << "Nhap diem thi: ";
	cin >> sv.diemThi;
}
void ReadData(List& l, int n)
{
	SinhVien sv;
	Node* p = nullptr;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		ReadSV(sv);
		p = InitNode(sv);
		if (p == nullptr)
		{
			cout << "Failed to read data" << endl;
			return;
		}
		InsertNode(l, p);
	}
}
void PrintDate(Date d)
{
	cout << d.ngay << "/" << d.thang << "/" << d.nam;
}
void Print(List l)
{
	cout << setw(15) << "MSSV";
	cout << setw(30) << "HO VA TEN";
	cout << setw(12) << "NGAY SINH";
	cout << setw(20) << "DIEM THI";
	cout << endl;
	Node* p = l.head;
	while (p != nullptr)
	{
		cout << setw(15) << p->info.mssv;
		cout << setw(30) << p->info.hoTen;
		cout << setw(12);
		PrintDate(p->info.ngaySinh);
		cout << setw(20) << p->info.diemThi;
		cout << endl;
		p = p->next;
	}
}
void DeleteNode(List& l, const char* mssv)
{
	Node* q = nullptr;
	Node* p = l.head;
	if (l.head == nullptr)
	{
		cout << "Empty list" << endl;
		return;
	}
	while (p != nullptr && strcmp(p->info.mssv, mssv) != 0)
	{
		q = p;
		p = p->next;
	}
	if (p == nullptr)
	{
		cout << "Student doesn't exist" << endl;
		return;
	}
	if (p == l.head)
		l.head = l.head->next;
	else if (p == l.tail)
		l.tail = q;
	else
		q->next = p->next;
	delete p;
}
void InsertNode(List& l, Node* p)
{
	if (l.head == nullptr)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
int ThongKeGioi(List l)
{
	int s = 0;
	Node* p = l.head;
	while (p != nullptr)
	{
		if (p->info.diemThi >= 8.5)
			s++;
		p = p->next;
	}
	return s;
}
int ThongKeKha(List l)
{
	int s = 0;
	Node* p = l.head;
	while (p != nullptr)
	{
		if (p->info.diemThi >= 6.5 && p->info.diemThi < 8.5)
			s++;
		p = p->next;
	}
	return s;
}
int ThongKeTB(List l)
{
	int s = 0;
	Node* p = l.head;
	while (p != nullptr)
	{
		if (p->info.diemThi >= 4.5 && p->info.diemThi < 6.5)
			s++;
		p = p->next;
	}
	return s;
}
int ThongKeYeu(List l)
{
	int s = 0;
	Node* p = l.head;
	while (p != nullptr)
	{
		if (p->info.diemThi >= 0.5 && p->info.diemThi < 4.5)
			s++;
		p = p->next;
	}
	return s;
}
void ChuyenSinhVienDi(List& l)
{
	char* mssv = new char[10];
	cin.ignore();
	for (int i = 0; i < 2; i++)
	{
		cout << "Nhap ma so sinh vien chuyen di: ";
		cin.getline(mssv, 10);
		DeleteNode(l, mssv);
	}
}
void ChuyenSinhVienVao(List& l, int m) 
{
	ReadData(l, m);
}
void SwapNode(Node*& p, Node*& q)
{
	SinhVien temp = p->info;
	p->info = q->info;
	q->info = temp;
}
void BubbleSort(List& l)
{
	int flag;

	Node* q; 
	Node* p = nullptr;
	do
	{
		flag = 0;
		q = l.head;
		while (q->next != p)
		{
			if (q->info.diemThi > q->next->info.diemThi)
			{
				SwapNode(q, q->next);
				flag = 1;
			}
			q = q->next;
		}
		p = q;

	} while (flag);
}
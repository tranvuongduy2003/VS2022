#include <iostream>
#include <string>
using namespace std;

class DoVat 
{
public:
	string name;
	double gia;
	string nhaSanXuat;
	virtual void Nhap()
	{
		cin >> name >> gia >> nhaSanXuat;
	}
};

class Ao : public DoVat
{
public:
	string mauSac;
	virtual void Nhap()
	{
		DoVat::Nhap();
		cin >> mauSac;
	}
};

class NganTay : public Ao
{
public:
	bool coCoTay;
	void Nhap()
	{
		Ao::Nhap();
		cin >> coCoTay;
	}
};

class DaiTay : public Ao
{
public:
	double chieuDaiOngTay;
	void Nhap()
	{
		Ao::Nhap();
		cin >> chieuDaiOngTay;
	}
};

class Quan : public DoVat
{
public:
	double chieuDai;
	virtual void Nhap()
	{
		DoVat::Nhap();
		cin >> chieuDai;
	}
};

class Jean : public Quan
{
public:
	void Nhap()
	{
		Quan::Nhap();
		gia *= 0.8;
	}
};

class Kaki : public Quan
{
public:
	void Nhap()
	{
		Quan::Nhap();
		gia *= 1.5;
	}
};

class Mu : public DoVat
{
public:
	int level;
	double chiSoBuff;
	void Nhap()
	{
		DoVat::Nhap();
		cin >> level;
	}
};

class Sat : public Mu
{
public:
	Sat()
	{
		chiSoBuff = 1;
	}
};

class Bac : public Mu
{
public:
	Bac()
	{
		chiSoBuff = 1.5;
	}
};

class Vang : public Mu
{
public:
	Vang()
	{
		chiSoBuff = 3.0;
	}
};

int main()
{
	int n, option;
	cin >> n;
	DoVat** doVat = new DoVat * [n];
	for (int i = 0; i < n; i++)
	{
		cin >> option;
		cin.ignore();
		if (option == 1)
			doVat[i] = new Jean;
		if (option == 2)
			doVat[i] = new Kaki;
		if (option == 3)
			doVat[i] = new NganTay;
		if (option == 4)
			doVat[i] = new DaiTay;
		if (option == 5)
			doVat[i] = new Sat;
		if (option == 6)
			doVat[i] = new Bac;
		if (option == 7)
			doVat[i] = new Vang;
		doVat[i]->Nhap();
	}

	for (int i = 0; i < n; i++)
		doVat[i]->Xuat();

	delete[] doVat;

	return 0;
}
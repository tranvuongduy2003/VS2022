#include <iostream>
#include <string>
using namespace std;

class Tuong
{
public:
	string ten;
	int giaTri;
	double attack;
	double defend;
	string toc;
	string he;
	virtual double SatThuong(int luot) = 0;
	void Nhap()
	{
		cin >> attack >> defend;
	}
	void Xuat(int luot)
	{
		cout << ten << " - sat thuong gay ra: " << SatThuong(luot) << endl;
	}
};

class Jarvan : public Tuong
{
public:
	Jarvan()
	{
		ten = "Jarvan";
		toc = "Cong nghe";
		he = "Dau si";
		giaTri = 1;
	}
	void CapNhatChiSo(int qDauSi, int qCongNghe)
	{
		if (qDauSi == 2)
			defend += 15;
		else if (qDauSi == 3)
			defend += 30;
		if (qCongNghe == 2)
		{
			attack += 15;
			defend += 15;
		}
	}
	double SatThuong(int luot)
	{
		return luot * (defend * 2);
	}
};
class Reksai : public Tuong
{
public:
	Reksai()
	{
		ten = "Reksai";
		toc = "Tien cong";
		he = "Dau si";
		giaTri = 2;
	}
	void CapNhatChiSo(int qDauSi, int qTienCong)
	{
		if (qDauSi == 2)
			defend += 15;
		else if (qDauSi == 3)
			defend += 30;
		if (qTienCong == 2)
			attack += 30;
	}
	double SatThuong(int luot)
	{
		int t = (int)luot / 4;
		return attack * 2 * t + attack * (luot - t);

	}
};
class Sivir : public Tuong
{
public:
	Sivir()
	{
		ten = "Sivir";
		toc = "Cong nghe";
		he = "";
		giaTri = 4;
	}
	void CapNhatChiSo(int qCongNghe)
	{
		if (qCongNghe == 2)
		{
			attack += 15;
			defend += 15;
		}
	}
	double SatThuong(int luot)
	{
		return luot * 2 * attack;
	}
};
class Illaoi : public Tuong
{
public:
	Illaoi()
	{
		ten = "Illaoi";
		toc = "Tien cong";
		he = "Dau si";
		giaTri = 1;
	}
	void CapNhatChiSo(int qDauSi, int qTienCong)
	{
		if (qDauSi == 2)
			defend += 15;
		else if (qDauSi == 3)
			defend += 30;
		if (qTienCong == 2)
			attack += 30;
	}
	double SatThuong(int luot)
	{
		return luot * (attack + defend) / 2;
	}
};


int main()
{
	int n, luot, option, qJarvan = 0, qReksai = 0, qSivir = 0, qIllaoi = 0;
	int qCongNghe = 0, qDauSi = 0, qTienCong = 0;
	int giaTri = 0;
	cin >> n >> luot;
	Tuong** tuong = new Tuong * [n];
	for (int i = 0; i < n; i++)
	{
		cin >> option;
		if (option == 1)
		{
			tuong[i] = new Jarvan;
			qJarvan = 1;
		}
		if (option == 2)
		{
			tuong[i] = new Reksai;
			qReksai = 1;
		}
		if (option == 3)
		{
			tuong[i] = new Sivir;
			qSivir = 1;
		}
		if (option == 4)
		{
			tuong[i] = new Illaoi;
			qIllaoi = 1;
		}
		tuong[i]->Nhap();
	}

	qCongNghe = qJarvan + qSivir;
	qDauSi = qJarvan + qReksai + qIllaoi;
	qTienCong = qReksai + qIllaoi;

	for (int i = 0; i < n; i++)
	{
		if (tuong[i]->ten == "Jarvan")
			((Jarvan*)tuong[i])->CapNhatChiSo(qDauSi, qCongNghe);
		if (tuong[i]->ten == "Reksai")
			((Reksai*)tuong[i])->CapNhatChiSo(qDauSi, qTienCong);
		if (tuong[i]->ten == "Sivir")
			((Sivir*)tuong[i])->CapNhatChiSo(qCongNghe);
		if (tuong[i]->ten == "Illaoi")
			((Illaoi*)tuong[i])->CapNhatChiSo(qDauSi, qTienCong);
		giaTri += tuong[i]->giaTri;
	}

	for (int i = 0; i < n; i++)
		tuong[i]->Xuat(luot);

	cout << "Tong gia tri: " << giaTri;

	delete[] tuong;

	return 0;
}
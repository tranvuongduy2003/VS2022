#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


class Tuong
{
protected:
	int Loai;
	string Ten;
	int GiaTri;
	int ChiSoAttack;
	int ChiSoDefend;
	int SatThuong;
public:
	virtual void Nhap()
	{
		cin >> ChiSoAttack >> ChiSoDefend;
	}
	virtual void Xuat()
	{
		cout << Ten << " - " << "sat thuong gay ra: " << ChiSoAttack << endl;
	}
	virtual void TinhPhongThu2()
	{
		return;
	}
	virtual void TinhPhongThu3()
	{
		return;
	}
	virtual void TinhTanCong2()
	{
		return;
	}

	virtual void SatThuongTheoLuot(int luot)
	{
		return;
	}
	virtual int GetLoai()
	{
		return Loai;
	}
	virtual int GetGiaTri()
	{
		return GiaTri;
	}
};

class Jarva :public Tuong
{
public:
	void Nhap()
	{
		Tuong::Nhap();
		Ten = "Jarva";
		Loai = 1;
		GiaTri = 1;
	}
	void TinhPhongThu2()
	{
		ChiSoDefend += 15;
	}
	void TinhPhongThu3()
	{
		ChiSoDefend += 30;
	}
	void TinhTanCong2()
	{
		ChiSoAttack += 15;
	}
	void SatThuongTheoLuot(int luot)
	{
		ChiSoAttack = ChiSoDefend * 2 * luot;
	}
};

class Reksai :public Tuong
{
public:
	void Nhap()
	{
		Tuong::Nhap();
		Ten = "Reksai";
		Loai = 2;
		GiaTri = 2;
	}
	void TinhPhongThu2()
	{
		ChiSoDefend += 15;
	}
	void TinhPhongThu3()
	{
		ChiSoDefend += 30;
	}
	void TinhTanCong2()
	{
		ChiSoAttack += 30;
	}
	void SatThuongTheoLuot(int luot)
	{
		ChiSoAttack = ChiSoAttack * 2 * luot;
	}
};

class Sivir :public Tuong
{
public:
	void Nhap()
	{
		Tuong::Nhap();
		Ten = "Sivir";
		Loai = 3;
		GiaTri = 4;
	}
	void TinhPhongThu2()
	{
		ChiSoDefend += 15;
	}
	void TinhTanCong2()
	{
		ChiSoAttack += 15;
	}
	void SatThuongTheoLuot(int luot)
	{
		ChiSoAttack = ChiSoAttack * 2 * luot;
	}
};

class Illaoi :public Tuong
{
public:
	void Nhap()
	{
		Tuong::Nhap();
		Ten = "Illaoi";
		Loai = 4;
		GiaTri = 1;
	}
	void TinhPhongThu2()
	{
		ChiSoDefend += 15;
	}
	void TinhPhongThu3()
	{
		ChiSoDefend += 30;
	}
	void TinhTanCong2()
	{
		ChiSoAttack += 30;
	}
	void SatThuongTheoLuot(int luot)
	{
		ChiSoAttack = luot * ((ChiSoAttack + ChiSoDefend) / 2);
	}

};

class Game
{
protected:
	int Luot;
	int TongGiaTri;
	int n;
	Tuong* ds[1000];
public:
	void Nhap()
	{

		cin >> n;
		int x;
		cin >> Luot;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			switch (x)
			{
			case 1:
				ds[i] = new Jarva;
				break;
			case 2:
				ds[i] = new Reksai;
				break;
			case 3:
				ds[i] = new Sivir;
				break;
			case 4:
				ds[i] = new Illaoi;
				break;
			}
			ds[i]->Nhap();
		}
	}
	int SoDauSi()
	{
		int Dem = 0;
		for (int i = 0; i < n; i++)
			if (ds[i]->GetLoai() != 3)
				Dem++;
		return Dem;
	}

	int SoTienCong()
	{
		int Dem = 0;
		for (int i = 0; i < n; i++)
			if (ds[i]->GetLoai() == 2 || ds[i]->GetLoai() == 4)
				Dem++;
		return Dem;
	}

	int SoCongNghe()
	{
		int Dem = 0;
		for (int i = 0; i < n; i++)
			if (ds[i]->GetLoai() == 3 || ds[i]->GetLoai() == 1)
				Dem++;
		return Dem;
	}

	void TinhToan()
	{
		TongGiaTri = 0;
		for (int i = 0; i < n; i++)
		{
			if (SoDauSi() == 2)
			{
				if (ds[i]->GetLoai() != 3)
					ds[i]->TinhPhongThu2();
			}
			if (SoDauSi() >= 3)
			{
				if (ds[i]->GetLoai() != 3)
					ds[i]->TinhPhongThu3();
			}

			if (SoTienCong() >= 2)
			{
				if (ds[i]->GetLoai() == 2 || ds[i]->GetLoai() == 4)
					ds[i]->TinhTanCong2();
			}

			if (SoCongNghe() >= 2)
			{
				if (ds[i]->GetLoai() == 1 || ds[i]->GetLoai() == 3)
					ds[i]->TinhPhongThu2();
				ds[i]->TinhTanCong2();
			}
			if (ds[i]->GetLoai() == 2)
				ds[i]->SatThuongTheoLuot(Luot / 4);
			else
				ds[i]->SatThuongTheoLuot(Luot);
			TongGiaTri += ds[i]->GetGiaTri();
		}
	}
	void Xuat()
	{
		for (int i = 0; i < n; i++)
		{
			ds[i]->Xuat();
		}
		cout << TongGiaTri;
	}

};

int main()
{
	Game a;
	a.Nhap();
	a.TinhToan();
	a.Xuat();
	return 0;
}
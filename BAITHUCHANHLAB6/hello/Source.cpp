#include <iostream>
#include <string>
using namespace std;



//=====================CPU=======================
class CPU
{
public:
	string ma;
	string loai;
	string hang;
	int soCore;
	double xungNhip;
	double giaNhap;
	void Nhap()
	{
		getline(cin, ma);
	}
	void Xuat()
	{
		cout << "CPU: " << ma << " " << loai << " " << hang << " " << soCore << " " << xungNhip << " " << giaNhap << endl;
	}
};
class Alpha : public CPU
{
public:
	Alpha()
	{
		loai = "Alpha";
		hang = "Black";
		soCore = 2;
		xungNhip = 1.8;
		giaNhap = 200;
	}
};
class Beta : public CPU
{
public:
	Beta()
	{
		loai = "Beta";
		hang = "Black";
		soCore = 4;
		xungNhip = 2.46;
		giaNhap = 400;
	}
};
class Gamma : public CPU
{
public:
	Gamma()
	{
		loai = "Gamma";
		hang = "White";
		soCore = 4;
		xungNhip = 2.6;
		giaNhap = 600;
	}
};



//===================== Vo =======================
class Vo
{
public:
	string ma;
	string loai;
	string hang;
	double giaNhap;
	int maMau;
	void Nhap()
	{
		getline(cin, ma);
		cin >> maMau;
	}
	void Xuat()
	{
		cout << "Vo smartphone: " << ma << " " << loai << " " << hang << " " << mauSac() << " " << giaNhap << endl;
	}
	virtual string mauSac() = 0;
};
class Nhom : public Vo
{
public:
	Nhom()
	{
		loai = "Nhom";
		hang = "Black";
		giaNhap = 400;
	}
	string mauSac()
	{
		if (maMau == 1)
			return "Do";
		else
			return "Den";
	}
};
class Nhua : public Vo
{
public:
	Nhua()
	{
		loai = "Nhua";
		hang = "White";
		giaNhap = 200;
	}
	string mauSac()
	{
		if (maMau == 1)
			return "Do";
		else if (maMau == 2)
			return "Den";
		else
			return "Xanh";
	}
};



//===================== Man hinh =======================
class ManHinh
{
public:
	string ma;
	string hang;
	string doPhanGiai;
	double giaNhap;
	double kichThuoc;
	ManHinh()
	{
		kichThuoc = 4.7;
	}
	virtual void Nhap()
	{
		getline(cin, ma);
		getline(cin, hang);
	}
	virtual void Xuat()
	{
		cout << "Man hinh: " << ma << " " << hang << " " << doPhanGiai << " " << giaNhap;
	}
};
class HD : public ManHinh
{
public:
	HD()
	{
		doPhanGiai = "HD";
		giaNhap = 200;
	}
	HD(string ma, string hang)
	{
		this->ma = ma;
		this->hang = hang;
		doPhanGiai = "HD";
		giaNhap = 200;
	}
	void Xuat()
	{
		ManHinh::Xuat();
		cout << endl;
	}
};
class FullHD : public ManHinh
{
public:
	bool chongLoa;
	FullHD()
	{
		doPhanGiai = "FullHD";
		giaNhap = 200;
	}
	FullHD(string ma, string hang)
	{
		this->ma = ma;
		this->hang = hang;
		doPhanGiai = "FullHD";
	}
	void Nhap()
	{
		ManHinh::Nhap();
		cin >> chongLoa;
		giaNhap = (chongLoa == true ? 500 : 300);
	}
	void Nhap(bool isChongLoa)
	{
		ManHinh::Nhap();
		chongLoa = isChongLoa;
		giaNhap = (chongLoa == true ? 500 : 300);
	}
	void Xuat()
	{
		ManHinh::Xuat();
		cout << " " << chongLoa << endl;
	}
};



//===================== Smartphone =======================
class Smartphone
{
public:
	string ma;
	string dong;
	Vo* vo;
	CPU* cpu;
	ManHinh* manHinh;
	virtual void Nhap()
	{
		getline(cin, ma);
	}
	void Xuat()
	{
		cout << "Smartphone: " << ma << " " << dong << " " << GiaBan() << endl;
		cpu->Xuat();
		manHinh->Xuat();
		vo->Xuat();
	}
	virtual double GiaBan() = 0;
};
class Venus : public Smartphone
{
public:
	Venus()
	{
		dong = "Venus";
	}
	void Nhap()
	{
		int maCPU, doPhanGiai, loaiVo;
		Smartphone::Nhap();
		cin >> maCPU;
		cin.ignore();
		if (maCPU == 1)
			cpu = new Alpha;
		if (maCPU == 2)
			cpu = new Beta;
		cpu->Nhap();
		manHinh = new ManHinh;
		manHinh->Nhap();
		cin >> doPhanGiai;
		if (doPhanGiai == 1)
			manHinh = new HD(manHinh->ma, manHinh->hang);
		if (doPhanGiai == 2)
			manHinh = new FullHD(manHinh->ma, manHinh->hang);
		cin >> loaiVo;
		cin.ignore();
		if (loaiVo == 1)
			vo = new Nhom;
		if (loaiVo == 2)
			vo = new Nhua;
		vo->Nhap();
	}
	double GiaBan()
	{
		return (vo->giaNhap + cpu->giaNhap + manHinh->giaNhap) * 1.3;
	}
};
class Mars : public Smartphone
{
public:
	Mars()
	{
		dong = "Mars";
		manHinh = new FullHD;
		vo = new Nhom;
	}
	void Nhap()
	{
		int maCPU;
		Smartphone::Nhap();
		cin >> maCPU;
		cin.ignore();
		if (maCPU == 1)
			cpu = new Alpha;
		if (maCPU == 2)
			cpu = new Beta;
		if (maCPU == 3)
			cpu = new Gamma;
		cpu->Nhap();
		manHinh->Nhap();
		cin.ignore();
		vo->Nhap();
	}
	double GiaBan()
	{
		return (vo->giaNhap + cpu->giaNhap + manHinh->giaNhap) * 1.5;
	}
};
class Jupiter : public Smartphone
{
public:
	Jupiter()
	{
		dong = "Jupiter";
		cpu = new Gamma;
		manHinh = new FullHD;
		vo = new Nhom;
	}
	void Nhap()
	{
		Smartphone::Nhap();
		cpu->Nhap();
		((FullHD*)manHinh)->Nhap(true);
		vo->Nhap();
	}
	double GiaBan()
	{
		return (vo->giaNhap + cpu->giaNhap + manHinh->giaNhap) * 1.8;
	}
};


int main()
{
	int n, dongMay;
	cin >> n;
	Smartphone** smartphone = new Smartphone * [n];
	for (int i = 0; i < n; i++)
	{
		cin >> dongMay;
		cin.ignore();
		if (dongMay == 1)
			smartphone[i] = new Venus;
		if (dongMay == 2)
			smartphone[i] = new Mars;
		if (dongMay == 3)
			smartphone[i] = new Jupiter;
		smartphone[i]->Nhap();
	}

	for (int i = 0; i < n; i++)
		smartphone[i]->Xuat();

	delete[] smartphone;

	return 0;
}
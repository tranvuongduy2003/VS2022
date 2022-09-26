#include <iostream>
using namespace std;

class Room
{
protected:
	int soDem;
	string loaiPhong;
public:
	Room() {};
	virtual void Nhap() = 0;
	void Xuat()
	{
		cout << "So dem: " << soDem << endl;
		cout << "Loai phong: " << loaiPhong << endl;
	}
	virtual float DoanhThu() = 0;
};

class Deluxe : public Room
{
private:
	int phiDichVu;
public:
	Deluxe()
	{
		soDem = 0;
		loaiPhong = "Deluxe";
	}
	virtual void Nhap()
	{
		cin >> soDem;
		cin >> phiDichVu;
	}
	virtual float DoanhThu()
	{
		return soDem * 750000 + phiDichVu + phiDichVu;
	}
};

class Premium : public Room
{
private:
	int phiDichVu;
public:
	Premium()
	{
		soDem = 0;
		loaiPhong = "Premium";
	}
	virtual void Nhap()
	{
		cin >> soDem;
		cin >> phiDichVu;
	}
	virtual float DoanhThu()
	{
		return soDem * 500000 + phiDichVu;
	}
};

class Business : public Room
{
public:
	Business()
	{
		soDem = 0;
		loaiPhong = "Business";
	}
	virtual void Nhap()
	{
		cin >> soDem;
	}
	virtual float DoanhThu()
	{
		return soDem * 300000;
	}
};

int main()
{
	return 0;
}

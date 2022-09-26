#include <iostream>
#include <string>
using namespace std;


class Ban
{
protected:
    string ten;
    int tuoi;
public:
    virtual void Nhap()
    {
        cin >> ten;
        cin >> tuoi;
    }

    virtual void Xuat()
    {
        return;
    }

    virtual float TG(int n) = 0;
    virtual int Loai() = 0;
};

class BanThan : public Ban
{
protected:
    int sdt;
public:
    void Nhap()
    {
        Ban::Nhap();
        cin >> sdt;
    }

    void Xuat()
    {
        cout << "Ten: " << ten << ", tuoi: " << tuoi << ", so dien thoai: " << sdt;
    }

    float TG(int n)
    {
        return 5;
    }

    int Loai()
    {
        return 1;
    }
};

class BanTrai : public Ban
{
protected:
    long thunhap;
public:
    void Nhap()
    {
        Ban::Nhap();
        cin >> thunhap;
    }

    void Xuat()
    {
        cout << "Ten: " << ten << ", tuoi: " << tuoi << ", thu nhap: " << thunhap << "d" << endl;
    }

    float TG(int n)
    {
        return (float)5 * thunhap / 10000000.0;
    }

    int Loai()
    {
        return 2;
    }

};

class BanTraiKhac : public Ban
{
protected:
    float dohapdan;
public:
    void Nhap()
    {
        Ban::Nhap();
        cin >> dohapdan;
    }

    float TG(int n)
    {
        return (float)dohapdan * 20 / n;
    }

    int Loai()
    {
        return 3;
    }

    void Xuat()
    {
        cout << "Ten: " << ten << ", tuoi: " << tuoi << ", do thu hut: ";
        if (dohapdan >= 0.7)
            cout << "cao";
        if (dohapdan >= 0.4 && dohapdan <= 0.7)
            cout << "trung binh";
        if (dohapdan < 0.4)
            cout << "thap";
    }
};

class Kaguya
{
public:
    int n;
    Ban* ds[100];
    void Nhap()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int loai; //1 bsf - 2 bf - 3 obf
            cin >> loai;
            switch (loai)
            {
            case 1:
                ds[i] = new BanThan;
                break;
            case 2:
                ds[i] = new BanTrai;
                break;
            case 3:
                ds[i] = new BanTraiKhac;
                break;
            }
            ds[i]->Nhap();



        }
    }

    void TGchoBan()
    {
        float TGBanThan = 0;
        float TGBanTrai = 0;
        float TGBTKhac = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds[i]->Loai() == 1)
                TGBanThan += ds[i]->TG(n);
            if (ds[i]->Loai() == 2)
                TGBanTrai += ds[i]->TG(n);
            if (ds[i]->Loai() == 3)
                TGBTKhac += ds[i]->TG(n);
        }
        cout << "Thong ke:" << endl;
        cout << "-Thoi gian danh cho ban than: " << TGBanThan << " h" << endl;
        cout << "-Thoi gian danh cho ban trai: " << TGBanTrai << " h" << endl;
        cout << "-Thoi gian danh cho ban trai khac: " << TGBTKhac << "h" << endl;
    }

    Ban* QuanTrong()
    {
        Ban* lc = ds[0];
        for (int i = 0; i < n; i++)
        {
            if (lc->TG(n) < ds[i]->TG(n))
                lc = ds[i];
        }
        return lc;
    }
};

int main()
{
    Kaguya K;
    K.Nhap();

    K.TGchoBan();
    cout << "Nguoi ban quan trong nhat:" << endl;
    K.QuanTrong()->Xuat();
    return 0;
}
class PS
{
	int tu, mau;
public:
	PS()
	{
		tu = 0;
		mau = 1;
	}
	PS(int tu, int mau)
	{
		this->tu = tu;
		this->mau = mau;
	}
	PS(int a)
	{
		tu = a;
		mau = 1;
	}

	PS operator + (PS a)
	{
		int tu = this->tu * a.mau + this->mau * a.tu;
		int mau = this->mau * a.mau;
		return PS(tu, mau);
	}
};

int main()
{
	PS kq, a(5, 3);

	kq = a + 5 + a;

	return 0;
}
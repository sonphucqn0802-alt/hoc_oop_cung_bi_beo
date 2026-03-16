
#include <iostream>
using namespace std;

class cPhanSo 
{
	private: 
		int iTuso;
		int iMauso;
	public:
		void Nhap();
		void Xuat();
		cPhanSo TinhTong(cPhanSo);
};

void cPhanSo::Nhap()
{
	cin >> iTuso >> iMauso;
}

void cPhanSo::Xuat()
{
	cout << iTuso <<"/"<< iMauso;
}

cPhanSo cPhanSo::TinhTong(cPhanSo p)
{
	cPhanSo kq;
	kq.iTuso=iTuso*p.iMauso+iMauso*p.iTuso;
	kq.iMauso=p.iMauso*iMauso;
	return kq;
}

int main() 
{
	cPhanSo p,q,kq;
	p.Nhap();
	q.Nhap();
	kq=p.TinhTong(q);
	p.Xuat();
     cout << endl;
	q.Xuat();
     cout << endl;
	kq.Xuat();	
}


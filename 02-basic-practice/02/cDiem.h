

#include <iostream>
using namespace std;

class cDiem {
     double dHoanhdo;
     double dTungdo;

     public:
          cDiem();
          cDiem(double, double);

          void Nhap();
          void Xuat();
          double GetHoanhDo();
          double GetTungDo();
          cDiem SetHoanhDo(double);
          cDiem SetTungDo(double);
          cDiem SetDiem(double,double);
          void TinhTien(double, double);

          ~cDiem();
};

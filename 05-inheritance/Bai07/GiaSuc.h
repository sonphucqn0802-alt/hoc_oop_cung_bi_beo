#include <cstdlib>
#include <iostream>
using namespace std;

class GiaSuc {
protected:
     int SoLuong;

public:
     GiaSuc() : SoLuong(0) {}

     void setSoLuong(int soLuong) {
          SoLuong = soLuong;
     }

     int getSoLuong() {
          return SoLuong;
     }
};

class Bo : public GiaSuc {
public:
     void keu() {
          cout << "Bo keu: Um bo" << endl;
     }

     int sinhCon() {
          int soCon = 0;
          for (int i = 0; i < SoLuong; i++) {
               soCon += rand() % 3 + 1;
          }
          SoLuong += soCon;
          return soCon;
     }

     int choSua() {
          int tongSua = 0;
          for (int i = 0; i < SoLuong; i++) {
               tongSua += rand() % 21;
          }
          return tongSua;
     }
};

class Cuu : public GiaSuc {
public:
     void keu() {
          cout << "Cuu keu: Be be" << endl;
     }

     int sinhCon() {
          int soCon = 0;
          for (int i = 0; i < SoLuong; i++) {
               soCon += rand() % 3 + 1;
          }
          SoLuong += soCon;
          return soCon;
     }

     int choSua() {
          int tongSua = 0;
          for (int i = 0; i < SoLuong; i++) {
               tongSua += rand() % 6;
          }
          return tongSua;
     }
};

class De : public GiaSuc {
public:
     void keu() {
          cout << "De keu: Beee beee" << endl;
     }

     int sinhCon() {
          int soCon = 0;
          for (int i = 0; i < SoLuong; i++) {
               soCon += rand() % 3 + 1;
          }
          SoLuong += soCon;
          return soCon;
     }

     int choSua() {
          int tongSua = 0;
          for (int i = 0; i < SoLuong; i++) {
               tongSua += rand() % 11;
          }
          return tongSua;
     }
};

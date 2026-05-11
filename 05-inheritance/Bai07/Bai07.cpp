//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27.1

/*Mot nong trai chan nuoi co 3 loai gia suc: bo, cuu, va de. Moi loai gia suc deu
co the sinh con, cho sua va phat ra tieng keu rieng cua chung.
Ap dung ke thua, xay dung chuong trinh cho phep nguoi chu nong trai nhap vao
so luong gia suc ban dau o moi loai.
a. Khi tat ca gia suc trong nong trai deu doi, cho biet nhung tieng keu nghe duoc.
b. Thong ke so luong gia suc moi loai va tong so lit sua sau mot lua sinh va mot
luot cho sua cua tat ca gia suc.*/

#include "GiaSuc.h"
#include <ctime>
using namespace std;

int main() {
     srand((unsigned int)time(NULL));

     int soBo, soCuu, soDe;
     Bo bo;
     Cuu cuu;
     De de;

     cout << "Nhap so luong bo ban dau: ";
     cin >> soBo;
     cout << "Nhap so luong cuu ban dau: ";
     cin >> soCuu;
     cout << "Nhap so luong de ban dau: ";
     cin >> soDe;

     bo.setSoLuong(soBo);
     cuu.setSoLuong(soCuu);
     de.setSoLuong(soDe);

     cout << "\nNhung tieng keu nghe duoc trong nong trai" << endl;
     if (bo.getSoLuong() > 0) {
          bo.keu();
     }
     if (cuu.getSoLuong() > 0) {
          cuu.keu();
     }
     if (de.getSoLuong() > 0) {
          de.keu();
     }

     int soBoCon = bo.sinhCon();
     int soCuuCon = cuu.sinhCon();
     int soDeCon = de.sinhCon();

     int suaBo = bo.choSua();
     int suaCuu = cuu.choSua();
     int suaDe = de.choSua();

     cout << "\nThong ke sau mot lua sinh" << endl;
     cout << "So bo con sinh ra: " << soBoCon << endl;
     cout << "So cuu con sinh ra: " << soCuuCon << endl;
     cout << "So de con sinh ra: " << soDeCon << endl;

     cout << "\nSo luong gia suc sau khi sinh" << endl;
     cout << "So luong bo: " << bo.getSoLuong() << endl;
     cout << "So luong cuu: " << cuu.getSoLuong() << endl;
     cout << "So luong de: " << de.getSoLuong() << endl;

     cout << "\nThong ke sua sau mot luot cho sua" << endl;
     cout << "So lit sua bo: " << suaBo << endl;
     cout << "So lit sua cuu: " << suaCuu << endl;
     cout << "So lit sua de: " << suaDe << endl;
     cout << "Tong so lit sua: " << suaBo + suaCuu + suaDe << endl;

     return 0;
}

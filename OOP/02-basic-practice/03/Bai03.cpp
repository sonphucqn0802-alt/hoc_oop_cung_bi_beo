//Mã số sinh viên: 25521438
//Họ và tên sinh viên: Phạm Sơn Phúc
//Ngày sinh: 08/02/2007
//Lớp: IT002.Q27

/*Cài đặt lớp biểu diễn khái niệm số phức với hai thành phần dữ liệu thực, ảo và
các hàm thành phần xuất, nhập, định giá trị cho số phức, cộng, trừ, nhân, chia
hai số phức. Viết chương trình cho phép nhập vào hai số phức, in ra kết quả các
phép toán cộng, trừ, nhân, chia hai số phức kể trên.
*/

#include "cSoPhuc.h"
using namespace std;

int main() {
    cSoPhuc sp1;
    cSoPhuc sp2;
    
    sp1.Input();
    sp2.Input();
    sp1.Output();
    sp2.Output();
    
    sp1.Sum(sp2).Output();
    sp1.Sub(sp2).Output();
    sp1.Mul(sp2).Output();
    sp1.Div(sp2).Output();
    
    return 0;
}

cSoPhuc :: cSoPhuc (int thuc, int ao) {
    iThuc = thuc;
    iAo = ao;
}

cSoPhuc :: cSoPhuc() {
    iThuc = 0;
    iAo = 0;
}


void cSoPhuc :: Input() {
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "Nhap phan ao: ";
    cin >> iAo;
}

void cSoPhuc :: Output() {
    cout << iThuc << " + " << iAo << "i" << endl; 
}


void cSoPhuc :: SetValue(int thuc, int ao) {
    iThuc = thuc;
    iAo = ao;
}

cSoPhuc cSoPhuc :: Sum(cSoPhuc sp) {
     cSoPhuc result;
     result.iThuc = iThuc + sp.iThuc;
     result.iAo = iAo + sp.iAo;
     return result;
}

cSoPhuc cSoPhuc :: Sub(cSoPhuc sp) {
     cSoPhuc result;
     result.iThuc = iThuc - sp.iThuc;
     result.iAo = iAo - sp.iAo;
     return result;
}

cSoPhuc cSoPhuc :: Mul(cSoPhuc sp) {
     cSoPhuc result;
     result.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
     result.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
     return result;
}

cSoPhuc cSoPhuc :: Div(cSoPhuc sp) {
     cSoPhuc result;
     result.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / (sp.iThuc * sp.iThuc + sp.iAo * sp.iAo);
     result.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / (sp.iThuc * sp.iThuc + sp.iAo * sp.iAo);
     return result;
}

cSoPhuc :: ~cSoPhuc() {
    
}


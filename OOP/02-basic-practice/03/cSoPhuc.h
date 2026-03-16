#include <iostream>
using namespace std;

class cSoPhuc {
     int iThuc;
     int iAo;

     public:
          //Constructor
          cSoPhuc();
          cSoPhuc(int, int);

          //Hàm thao tác
          void Input();
          void Output();
          void SetValue(int iThuc, int iAo);
          cSoPhuc Sum(cSoPhuc);
          cSoPhuc Sub(cSoPhuc);
          cSoPhuc Mul(cSoPhuc);
          cSoPhuc Div(cSoPhuc);
          //Destructor
          ~cSoPhuc();
};

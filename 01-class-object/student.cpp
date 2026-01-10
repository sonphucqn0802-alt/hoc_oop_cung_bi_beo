#include <bits/stdc++.h>
using namespace std;
// Class là một thực thể mô tả các thuộc tính và hành vi của một đối tượng
// Class không chạy được, chỉ tạo ra các đối tượng
class Student {
public: 
    string name;
    int age;
    string gender;
    float gpa;    
};

int main() {
    // Khai báo biến s1 là một đối tượng của class Student, người ta gọi là object
    // Object là một biến cụ thể của class
     Student s1;
     cout << "Name: ";
     getline(cin, s1.name); cout << endl;

     cout << "Gender: ";
     getline(cin, s1.gender); cout << endl;

     cout << "GPA: ";
     cin >> s1.gpa; cout << endl;

     cout << "Age: ";
     cin >> s1.age; cout << endl;


     cout << "Name: " << s1.name << endl;
     cout << "Age: " << s1.age << endl;
     cout << "Gender: " << s1.gender << endl;
     cout << "GPA: " << s1.gpa << endl;
     
     return 0;
}
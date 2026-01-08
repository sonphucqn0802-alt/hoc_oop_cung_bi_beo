#include <bits/stdc++.h>
using namespace std;

class Student {
public: 
    string name;
    int age;
    string gender;
    float gpa;    
};

int main() {

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
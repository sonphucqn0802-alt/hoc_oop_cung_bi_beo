#include <iostream>
#include <string>
using namespace std;


class Bus {
protected:
     string id;
     string driverName;
     string carNumber;
     double revenue;

public:
     Bus() : revenue(0) {}

     void inputBase() {
          cout << "Ma so chuyen: ";
          getline(cin, id);
          cout << "Ho ten tai xe: ";
          getline(cin, driverName);
          cout << "So xe: ";
          getline(cin, carNumber);
          cout << "Doanh thu: ";
          cin >> revenue;
          cin.ignore(10000, '\n');
     }

     void outputBase() const {
          cout << "Ma so chuyen: " << id << endl;
          cout << "Ho ten tai xe: " << driverName << endl;
          cout << "So xe: " << carNumber << endl;
          cout << "Doanh thu: " << revenue << endl;
     }

     double getRevenue() const {
          return revenue;
     }

};

class LocalBus : public Bus {
private:
     string routeNumber;
     double distance;

public:
     LocalBus() : distance(0) {}

     void input() {
          inputBase();
          cout << "So tuyen: ";
          getline(cin, routeNumber);
          cout << "So km di duoc: ";
          cin >> distance;
          cin.ignore(10000, '\n');
     }

     void output() const {
          outputBase();
          cout << "So tuyen: " << routeNumber << endl;
          cout << "So km di duoc: " << distance << endl;
     }
};

class LongDistanceBus : public Bus {
private:
     string destination;
     int numberOfDays;

public:
     LongDistanceBus() : numberOfDays(0) {}

     void input() {
          inputBase();
          cout << "Noi den: ";
          getline(cin, destination);
          cout << "So ngay di duoc: ";
          cin >> numberOfDays;
          cin.ignore(10000, '\n');
     }

     void output() const {
          outputBase();
          cout << "Noi den: " << destination << endl;
          cout << "So ngay di duoc: " << numberOfDays << endl;
     }
};


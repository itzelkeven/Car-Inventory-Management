#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car {
private:
        string _carName;
        string _carType;
        string _carMake;
        string _carTransmission;
        int _cost;
        int _year;
public:
        Car();
        Car(const string CARNAME, const string CARMAKE, const string CARTYPE, const int YEAR, const string CARTRANSMISSION, const int SELLPRICE);
        string getCarName();
        string getCarType();
        string getCarMake();
        string getCarTransmission();
        int getCarYear();
        int getPrice();
        int getYear();
        void displayAndPurchaseCarsWithinBudget(vector<Car*>& carInventory, int& budget);
        void financingPlan(vector<Car*>& carInventory, int& budget);

};
#endif

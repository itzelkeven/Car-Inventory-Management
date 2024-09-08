#include "Car.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Default constructor
Car::Car() {
    _carName = "";
    _carType = "";
    _carMake = "";
    _carTransmission = "";
    _cost = 0;
    _year = 0;
}

// Paramterized Constructor
Car::Car(const string CARMAKE, const string CARNAME, const string CARTYPE, const int YEAR, const string CARTRANSMISSION, const int SELLPRICE) {
    _carName = CARNAME;
    _carType = CARTYPE;
    _carMake = CARMAKE;
    _carTransmission = CARTRANSMISSION;
    _cost = SELLPRICE;
    _year = YEAR;
}
// Retrieve Car name
string Car::getCarName() {
    return _carName;
}

// Retrieve Car type
string Car::getCarType() {
    return _carType;
}

// Retrieve Car make
string Car::getCarMake() {
    return _carMake;
}

// Retrieve Car Transmission
string Car::getCarTransmission() {
    return _carTransmission;
}

// Retrieve Car Year
int Car::getCarYear() {
    return _year;
}

// Retrieve Car Price
int Car::getPrice() {
    return _cost;
}

// allow user to purchase and view viable cars
void displayAndPurchaseCarsWithinBudget(vector<Car*>& carInventory, int& budget) {
    // Variables to check whether we can purchase a car or not
    bool found = false;
    cout << "Cars within your budget:" << endl;
    // Make a new vector of integers containing the location of purchaseable cars
    vector<int> indexWithinBudget;

    // Check through our inventory vector and match prices with our current budget
    for (size_t i = 0; i < carInventory.size(); i++) {
        if (carInventory[i]->getPrice() <= budget) {
            cout << i + 1 << ". " << carInventory[i]->getCarMake() << " " << carInventory[i]->getCarName() << endl;
            cout << "Type: " << carInventory[i]->getCarType() << endl;
            cout << "Year: " << carInventory[i]->getCarYear() << endl;
            cout << "Transmission: " << carInventory[i]->getCarTransmission() << endl;
            cout << "Selling Price: $" << carInventory[i]->getPrice() << endl << endl;
            indexWithinBudget.push_back(i);
            found = true;
        }
    }

    // If no cars are found, break the loop
    if (!found) {
        cout << "No cars available withfin your budget." << endl;
        return;
    }
    // Proceed to ask user what they want to buy after displaying all options
    cout << "Enter the number of the car you wish to purchase or 0 to return: ";
    int selection;
    cin >> selection;

    if (selection > 0 && selection <= indexWithinBudget.size()) {
        int actualIndex = indexWithinBudget[selection - 1];
        Car* purchasedCar = carInventory[actualIndex];

        cout << "Congratulations on purchasing your " << purchasedCar->getCarMake() << " " << purchasedCar->getCarName() << endl;
        budget -= purchasedCar->getPrice();
        cout << "Your remaining budget is: $" << budget << endl;

        delete purchasedCar;  // Delete the dynamically allocated car object
        carInventory.erase(carInventory.begin() + actualIndex);  // Remove the pointer from the vector
        indexWithinBudget.erase(indexWithinBudget.begin() + (selection - 1));  // Adjust indices after purchase
    }
}

void financingPlan(vector<Car*>& carInventory, int& budget) {
    // Implement a financing plan for the car based on its make, type, and year
    // For example, a car from a more recent year might have a lower interest rate
    double interestRate;
    // Make a new vector of integers containing the location of purchaseable cars
    vector<int> indexWithinBudget;
    bool found = false;
    // Check through our inventory vector and match prices with our current budget
    for (size_t i = 0; i < carInventory.size(); i++) {
        if (carInventory[i]->getPrice() <= budget) {
            cout << i + 1 << ". " << carInventory[i]->getCarMake() << " " << carInventory[i]->getCarName() << endl;
            cout << "Type: " << carInventory[i]->getCarType() << endl;
            cout << "Year: " << carInventory[i]->getCarYear() << endl;
            cout << "Transmission: " << carInventory[i]->getCarTransmission() << endl;
            cout << "Selling Price: $" << carInventory[i]->getPrice() << endl << endl;
            indexWithinBudget.push_back(i);
            found = true;
        }
    }

    // If no cars are found, break the loop
    if (!found) {
        cout << "No cars available withfin your budget." << endl;
        return;
    }

     // Proceed to ask user what they want to buy after displaying all options
    cout << "Enter the number of the car you wish to purchase or 0 to return: ";
    int selection;
    cin >> selection;

    if (selection > 0 && selection <= indexWithinBudget.size()) {
        float downPayment;
        float monthlyPayment;
        int actualIndex = indexWithinBudget[selection - 1];
        Car* purchasedCar = carInventory[actualIndex];

        cout << "Congratulations on signing on your " << purchasedCar->getCarMake() << " " << purchasedCar->getCarName() << endl;
        cout << "How much do you want to put down?: ";
        cin >> downPayment;
        budget -= downPayment;
        cout << "Your remaining budget is: $" << budget << endl << endl;
        cout << "Enter the number of years you want to finance (1-5): ";
        int years;
        cin >> years;

        interestRate = 0.05;  // Example interest rate
        monthlyPayment = (purchasedCar->getPrice()/(years * 12)) + (interestRate * 100);

        cout << fixed << setprecision(2);
        cout << "Monthly Payment: $" << monthlyPayment << endl;

        cout << "Thank you for signing with us!" << endl;



        delete purchasedCar;  // Delete the dynamically allocated car object
        carInventory.erase(carInventory.begin() + actualIndex);  // Remove the pointer from the vector
        indexWithinBudget.erase(indexWithinBudget.begin() + (selection - 1));  // Adjust indices after purchase
    }
}

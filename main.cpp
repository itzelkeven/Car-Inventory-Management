#include "Car.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Forward declaration of the function, assuming it's implemented below or in another file
void displayAndPurchaseCarsWithinBudget(vector<Car*>& carInventory, int& budget);
void financingPlan(vector<Car*>& carInventory, int& budget);

int main() {
    // Collect the users budget
    int budget;
    cout << "Welcome to The Lot!" << endl;
    cout << "The FINEST Automobile Establishment for all of your Car Needs!" << endl;
    cout << endl;
    cout << "Please Enter Your Budget for Today's Visit: ";
    cin >> budget;

    // Open sample car inventory from lot.txt
    ifstream carData("lot.txt");
    if (!carData) {
        cout << "Failed to open lot.txt" << endl;
        return 1;
    }
    // Set up vector to store all car objects
    vector<Car*> carInventory;
    string currLine;
    // Read from the lot.txt file
    while (getline(carData, currLine)) {
        stringstream line(currLine);
        vector<string> words;
        string word;

        while (line >> word) {
            words.push_back(word);
        }

        if (words.size() < 6) continue;
        // Store the appropriate data into the appropriate variables
        int sellPrice = stoi(words.back()); words.pop_back();
        string carTransmission = words.back(); words.pop_back();
        int carYear = stoi(words.back()); words.pop_back();
        string carType = words.back(); words.pop_back();
        string carMake = words[0];
        string carName;
        for (size_t i = 1; i < words.size(); ++i) {
            carName += (i > 1 ? " " : "") + words[i];
        }
        // Make pointer of car object and pass it to the inventory vector
        Car* currCar = new Car(carMake, carName, carType, carYear, carTransmission, sellPrice);
        carInventory.push_back(currCar);
    }
    // Close the lot.txt file
    carData.close();

    int userChoice = 0;
    // Display options for the user
    while (userChoice != 3) {
        cout << "Would You Like to See the Full Lot (Press 1), Just the Cars you qualify for (Press 2), or Exit (Press 3)? ";
        cin >> userChoice;
        // Display all options regardless of budget
        if (userChoice == 1) {
            for (size_t i = 0; i < carInventory.size(); i++) {
                cout << i + 1 << ". " << carInventory[i]->getCarMake() << " " << carInventory[i]->getCarName() << endl;
                cout << "Type: " << carInventory[i]->getCarType() << endl;
                cout << "Year: " << carInventory[i]->getCarYear() << endl;
                cout << "Transmission: " << carInventory[i]->getCarTransmission() << endl;
                cout << "Selling Price: $" << carInventory[i]->getPrice() << endl << endl;
            }
        // Display options according to budget and let  user purchase
        } else if (userChoice == 2) {
            int purchaseChoice = 0;
            cout << "Would you like to purchase your vehicle in full (1), or, do you want to finance it? (2)" << endl;
            cin >> purchaseChoice;
            if (purchaseChoice == 1) {
                displayAndPurchaseCarsWithinBudget(carInventory, budget);
            } 
            else if (purchaseChoice == 2) {
                financingPlan(carInventory, budget);

            }
        // Otherwise quit the program
        } else if (userChoice == 3) {
            cout << "Thank you for visiting The Lot!" << endl;
            cout << "Have a great day!" << endl;
            break;  // Exit the loop
        }
    }
    return 0;
}

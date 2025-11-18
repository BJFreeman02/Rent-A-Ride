#include <iostream>
#include "rentalsystem.h"

RentalSystem::RentalSystem() : totalRevenue(0) {
    initializeFleet();
}

RentalSystem::~RentalSystem() {
    for (auto vehicle : fleet) {
        delete vehicle;
    }
}

void RentalSystem::initializeFleet() {
    fleet.push_back(new Car("Honda", "Civic", 25.0));
    fleet.push_back(new Car("Toyota", "Corolla", 23.0));
    fleet.push_back(new Car("Ford", "Focus", 27.0));
    fleet.push_back(new SUV("Honda", "CR-V", 35.0, 5));
    fleet.push_back(new SUV("Toyota", "RAV4", 38.0, 5));
}

void RentalSystem::displayAvailableCars() {
    cout << "\n=== CARS AVAILABLE ===" << endl;
    for (int i = 0; i < fleet.size(); i++) {
        if (fleet[i]->getAvailability()) {
            cout << i << ". ";
            fleet[i]->displayInfo();
        }
    }
}

void RentalSystem::displayRentedCars() {
    cout << "\n=== RENTED CARS ===" << endl;
    if (rentedCars.empty()) {
        cout << "No cars rented out." << endl;
        return;
    }
    for (const auto& car : rentedCars) {
        car->displayInfo();
    }
}

void RentalSystem::rentCar(int index) {
    if (index < 0 || index >= fleet.size()) {
        cout << "Invalid car choice!" << endl;
        return;
    }
    
    Vehicle* car = fleet[index];
    if (!car->getAvailability()) {
        cout << "Sorry, that car is already rented!" << endl;
        return;
    }
    
    car->setAvailability(false);
    rentedCars.push_back(car);
    
    cout << "\nSUCCESS! You rented: ";
    car->displayInfo();
    cout << "Return within 1 day to avoid late fees!" << endl;
    
    cout << "\nRemaining available cars:" << endl;
    displayAvailableCars();
}

void RentalSystem::returnCar(int index, int daysLate) {
    if (index < 0 || index >= fleet.size()) {
        cout << "Invalid car!" << endl;
        return;
    }
    
    Vehicle* car = fleet[index];
    if (car->getAvailability()) {
        cout << "This car wasn't rented!" << endl;
        return;
    }
    
    double cost = car->getDailyRate();
    double lateFee = 0;
    
    if (daysLate > 0) {
        lateFee = daysLate * 15.0; // $15 per day late
        cout << "Late return! Fee: $" << lateFee << endl;
    }
    
    double total = cost + lateFee;
    totalRevenue += total;
    
    car->setAvailability(true);
    for (auto it = rentedCars.begin(); it != rentedCars.end(); ++it) {
        if (*it == car) {
            rentedCars.erase(it);
            break;
        }
    }
    
    cout << "Returned: ";
    car->displayInfo();
    cout << "Total charge: $" << total << endl;
}

void RentalSystem::displayStats() {
    cout << "\n=== SYSTEM STATS ===" << endl;
    cout << "Total cars: " << fleet.size() << endl;
    cout << "Available: " << (fleet.size() - rentedCars.size()) << endl;
    cout << "Rented: " << rentedCars.size() << endl;
    cout << "Revenue: $" << totalRevenue << endl;
}
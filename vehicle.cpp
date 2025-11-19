#include <iostream>
#include "vehicle.h"

// VEHICLE CLASS IMPLEMENTATION

// Constructor: Initializes vehicle properties and sets availability to true
Vehicle::Vehicle(string m, string md) 
    : make(m), model(md), isAvailable(true) {}

// Displays basic vehicle information (make, model, availability)
void Vehicle::displayInfo() const {
    cout << make << " " << model;
    cout << " | " << (isAvailable ? "Available" : "Rented");
}

// Returns the current availability status of the vehicle
bool Vehicle::getAvailability() const { 
    return isAvailable; 
}

// Updates the availability status of the vehicle
void Vehicle::setAvailability(bool available) { 
    isAvailable = available; 
}

// CAR CLASS IMPLEMENTATION

// Constructor: Calls base Vehicle constructor to initialize car properties
Car::Car(string m, string md) : Vehicle(m, md) {}

// Displays car information with [CAR] prefix
void Car::displayInfo() const {
    cout << "[CAR] ";
    Vehicle::displayInfo();  // Call base class display function
    cout << endl;
}

// SUV CLASS IMPLEMENTATION

// Constructor: Initializes SUV with capacity and calls base Vehicle constructor
SUV::SUV(string m, string md, int cap) 
    : Vehicle(m, md), capacity(cap) {}

// Displays SUV information with [SUV] prefix and passenger capacity
void SUV::displayInfo() const {
    cout << "[SUV] ";
    Vehicle::displayInfo();  // Call base class display function
    cout << " | Fits " << capacity << " people" << endl;
}

// RENTALSYSTEM CLASS IMPLEMENTATION

// Constructor: Initializes the rental system and creates the vehicle fleet
RentalSystem::RentalSystem() {
    initializeFleet();
}

// Destructor: Cleans up all dynamically allocated vehicle objects to prevent memory leaks
RentalSystem::~RentalSystem() {
    for (auto vehicle : fleet) {
        delete vehicle;  // Free memory for each vehicle object
    }
}

// Populates the fleet with a default set of vehicles (2 cars and 2 SUVs)
void RentalSystem::initializeFleet() {
    // Add cars to the fleet
    fleet.push_back(new Car("Honda", "Civic"));
    fleet.push_back(new Car("Toyota", "Corolla"));
    fleet.push_back(new Car("Ford", "Focus"));
    
    // Add SUVs to the fleet with their passenger capacities
    fleet.push_back(new SUV("Honda", "CR-V", 5));
    fleet.push_back(new SUV("Toyota", "RAV4", 5));
}

// Displays all vehicles that are currently available for rental
void RentalSystem::displayAvailableCars() {
    cout << "\n=== AVAILABLE CARS ===" << endl;
    bool foundAvailable = false;
    
    // Iterate through all vehicles in the fleet
    for (int i = 0; i < fleet.size(); i++) {
        if (fleet[i]->getAvailability()) {
            cout << i << ". ";  // Display index for user selection
            fleet[i]->displayInfo();  // Display vehicle information
            foundAvailable = true;
        }
    }
    
    // Message if no vehicles are available
    if (!foundAvailable) {
        cout << "No cars available for rental." << endl;
    }
}

// Displays all vehicles that are currently rented out
void RentalSystem::displayRentedCars() {
    cout << "\n=== RENTED CARS ===" << endl;
    
    // Check if there are any rented cars
    if (rentedCars.empty()) {
        cout << "No cars currently rented." << endl;
        return;
    }
    
    // Display information for each rented vehicle
    for (const auto& car : rentedCars) {
        car->displayInfo();
    }
}

// Rents a vehicle from the fleet based on the provided index
void RentalSystem::rentCar(int index) {
    // Validate the index is within bounds
    if (index < 0 || index >= fleet.size()) {
        cout << "Invalid car selection!" << endl;
        return;
    }
    
    // Get pointer to the selected vehicle
    Vehicle* car = fleet[index];
    
    // Check if the vehicle is already rented
    if (!car->getAvailability()) {
        cout << "Car is already rented!" << endl;
        return;
    }
    
    // Update vehicle status and add to rented cars list
    car->setAvailability(false);
    rentedCars.push_back(car);
    
    // Confirm successful rental
    cout << "Successfully rented: ";
    car->displayInfo();
}

// Returns a rented vehicle back to the available fleet
void RentalSystem::returnCar(int index) {
    // Validate the index is within bounds
    if (index < 0 || index >= fleet.size()) {
        cout << "Invalid car selection!" << endl;
        return;
    }
    
    // Get pointer to the selected vehicle
    Vehicle* car = fleet[index];
    
    // Check if the vehicle is actually rented
    if (car->getAvailability()) {
        cout << "This car is not currently rented!" << endl;
        return;
    }
    
    // Update vehicle status to available
    car->setAvailability(true);
    
    // Remove vehicle from rented cars list
    for (auto it = rentedCars.begin(); it != rentedCars.end(); ++it) {
        if (*it == car) {
            rentedCars.erase(it);
            break;
        }
    }
    
    // Confirm successful return
    cout << "Successfully returned: ";
    car->displayInfo();
}
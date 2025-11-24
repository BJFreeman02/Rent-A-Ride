#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <vector>
using namespace std;

// Base class for all vehicles in the rental system
class Vehicle {
protected:
    string make;        // Manufacturer of the vehicle (e.g., Honda, Toyota)
    string model;       // Model of the vehicle (e.g., Civic, Corolla)
    bool isAvailable;   // Availability status (true = available, false = rented)

public:
    // Constructor: Initializes vehicle with make, model and sets availability to true
    Vehicle(string m, string md);
    
    // Displays vehicle information (make, model, availability)
    virtual void displayInfo() const;
    
    // Returns the availability status of the vehicle
    bool getAvailability() const;
    
    // Sets the availability status of the vehicle
    void setAvailability(bool available);
    
    // Virtual destructor for proper cleanup of derived classes
    virtual ~Vehicle() {}
};

// Derived class for standard cars
class Car : public Vehicle {
public:
    // Constructor: Initializes car with make and model
    Car(string m, string md);
    
    // Overrides displayInfo to show car-specific information
    void displayInfo() const override;
};

// Derived class for SUVs with passenger capacity
class SUV : public Vehicle {
private:
    int capacity;  // Maximum number of passengers the SUV can hold

public:
    // Constructor: Initializes SUV with make, model, and passenger capacity
    SUV(string m, string md, int cap);
    
    // Overrides displayInfo to show SUV-specific information including capacity
    void displayInfo() const override;
};

// Main rental system class that manages the vehicle fleet and rental operations
class RentalSystem {
private:
    vector<Vehicle*> fleet;       // Collection of all vehicles in the system
    vector<Vehicle*> rentedCars;  // Collection of currently rented vehicles

public:
    // Constructor: Initializes the rental system and creates the vehicle fleet
    RentalSystem();
    
    // Destructor: Cleans up dynamically allocated vehicle objects
    ~RentalSystem();
    
    // Populates the fleet with default vehicles (cars and SUVs)
    void initializeFleet();
    
    // Displays all vehicles that are currently available for rental
    void displayAvailableCars();
    
    // Displays all vehicles that are currently rented out
    void displayRentedCars();
    
    // Rents a vehicle from the fleet based on index
    void rentCar(int index);
    
    // Returns a rented vehicle back to the available fleet
    void returnCar(int index);
};

#endif
#include <iostream>
#include "vehicle.h"

Vehicle::Vehicle(string m, string md, double rate) 
    : make(m), model(md), dailyRate(rate), isAvailable(true) {}

void Vehicle::displayInfo() const {
    cout << make << " " << model << " | $" << dailyRate << "/day";
    cout << " | " << (isAvailable ? "Available" : "Rented");
}

bool Vehicle::getAvailability() const { return isAvailable; }
double Vehicle::getDailyRate() const { return dailyRate; }
void Vehicle::setAvailability(bool available) { isAvailable = available; }

Car::Car(string m, string md, double rate) : Vehicle(m, md, rate) {}
void Car::displayInfo() const {
    cout << "[CAR] ";
    Vehicle::displayInfo();
    cout << endl;
}

SUV::SUV(string m, string md, double rate, int cap) 
    : Vehicle(m, md, rate), capacity(cap) {}

void SUV::displayInfo() const {
    cout << "[SUV] ";
    Vehicle::displayInfo();
    cout << " | Fits " << capacity << " people" << endl;
}
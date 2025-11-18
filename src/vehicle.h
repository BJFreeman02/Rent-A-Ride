#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    double dailyRate;
    bool isAvailable;

public:
    Vehicle(string m, string md, double rate);
    virtual void displayInfo() const;
    bool getAvailability() const;
    double getDailyRate() const;
    void setAvailability(bool available);
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string m, string md, double rate);
    void displayInfo() const override;
};

class SUV : public Vehicle {
private:
    int capacity;
public:
    SUV(string m, string md, double rate, int cap);
    void displayInfo() const override;
};

#endif
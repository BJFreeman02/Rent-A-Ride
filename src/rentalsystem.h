#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H
#include "vehicle.h"
#include <vector>

class RentalSystem {
private:
    vector<Vehicle*> fleet;
    vector<Vehicle*> rentedCars;
    double totalRevenue;

public:
    RentalSystem();
    ~RentalSystem();
    void initializeFleet();
    void displayAvailableCars();
    void displayRentedCars();
    void rentCar(int index);
    void returnCar(int index, int daysLate = 0);
    void displayStats();
};

#endif
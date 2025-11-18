#include <iostream>
#include "rentalsystem.h"

void runDemo() {
    RentalSystem campusRentals;
    
    cout << "=== CAMPUS CAR RENTAL DEMO ===" << endl;
    
    // Show starting state
    campusRentals.displayAvailableCars();
    campusRentals.displayStats();
    
    // Rent some cars
    cout << "\n--- Renting Car #1 (Honda Civic) ---" << endl;
    campusRentals.rentCar(0);
    
    cout << "\n--- Renting Car #4 (Honda CR-V) ---" << endl;
    campusRentals.rentCar(3);
    
    // Show rented cars
    campusRentals.displayRentedCars();
    
    // Return cars
    cout << "\n--- Returning Car #1 (On Time) ---" << endl;
    campusRentals.returnCar(0);
    
    cout << "\n--- Returning Car #4 (2 Days Late) ---" << endl;
    campusRentals.returnCar(3, 2);
    
    // Final stats
    campusRentals.displayStats();
}

int main() {
    cout << "Choose mode:" << endl;
    cout << "1. Demo Mode" << endl;
    cout << "2. Test Mode" << endl;
    cout << "Enter choice (1 or 2): ";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        runDemo();
    } else {
        // For test mode, we'll compile with test.cpp instead
        cout << "Compile with test.cpp for test mode:" << endl;
        cout << "g++ -c vehicle.cpp rentalsystem.cpp test.cpp" << endl;
        cout << "g++ vehicle.o rentalsystem.o test.o -o campus_test" << endl;
        cout << "./campus_test" << endl;
    }
    
    return 0;
}
#include <iostream>
#include "vehicle.h"

// Displays the main menu options to the user
void displayMenu() {
    cout << "\n=== CAMPUS CAR RENTAL SYSTEM ===" << endl;
    cout << "1. View available cars" << endl;
    cout << "2. View rented cars" << endl;
    cout << "3. Rent a car" << endl;
    cout << "4. Return a car" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option (1-5): ";
}

// Main function: Entry point of the program
int main() {
    RentalSystem campusRental;  // Create rental system instance
    int choice;                 // Variable to store user's menu choice
    
    cout << "Welcome to Campus Car Rental System!" << endl;
    
    // Main program loop - continues until user chooses to exit
    do {
        displayMenu();      // Show menu options
        cin >> choice;      // Get user input
        
        // Process user's choice
        switch(choice) {
            case 1:
                // Display all available cars
                campusRental.displayAvailableCars();
                break;
                
            case 2:
                // Display all currently rented cars
                campusRental.displayRentedCars();
                break;
                
            case 3: {
                // Rent a car: get index from user and attempt rental
                int carIndex;
                cout << "Enter car number to rent: ";
                cin >> carIndex;
                campusRental.rentCar(carIndex);
                break;
            }
                
            case 4: {
                // Return a car: get index from user and attempt return
                int carIndex;
                cout << "Enter car number to return: ";
                cin >> carIndex;
                campusRental.returnCar(carIndex);
                break;
            }
                
            case 5:
                // Exit the program
                cout << "Thank you for using Campus Car Rental!" << endl;
                break;
                
            default:
                // Handle invalid menu choices
                cout << "Invalid option! Please try again." << endl;
        }
    } while (choice != 5);  // Continue until user chooses exit (option 5)
    
    return 0;  // Program ended successfully
}
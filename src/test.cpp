#include <iostream>
#include "rentalsystem.h"

void runTests() {
    cout << "=== RUNNING CAMPUS RENTAL TESTS ===" << endl;
    
    // Test 1: System Initialization
    cout << "\n--- TEST 1: System Initialization ---" << endl;
    RentalSystem testSystem;
    testSystem.displayAvailableCars();
    testSystem.displayStats();
    
    // Test 2: Rent Available Car
    cout << "\n--- TEST 2: Rent Available Car ---" << endl;
    cout << "Renting car at index 1 (Toyota Corolla)..." << endl;
    testSystem.rentCar(1);
    testSystem.displayRentedCars();
    
    // Test 3: Rent Same Car Again (Should Fail)
    cout << "\n--- TEST 3: Rent Already Rented Car ---" << endl;
    cout << "Trying to rent same car again..." << endl;
    testSystem.rentCar(1);
    
    // Test 4: Rent Another Car
    cout << "\n--- TEST 4: Rent Another Car ---" << endl;
    cout << "Renting car at index 3 (Honda CR-V)..." << endl;
    testSystem.rentCar(3);
    testSystem.displayRentedCars();
    
    // Test 5: Return Car On Time
    cout << "\n--- TEST 5: Return Car On Time ---" << endl;
    cout << "Returning Toyota Corolla (index 1) on time..." << endl;
    testSystem.returnCar(1);
    
    // Test 6: Return Car Late with Fees
    cout << "\n--- TEST 6: Return Car Late with Fees ---" << endl;
    cout << "Returning Honda CR-V (index 3) 3 days late..." << endl;
    testSystem.returnCar(3, 3);
    
    // Test 7: Invalid Car Index
    cout << "\n--- TEST 7: Invalid Car Index ---" << endl;
    cout << "Trying to rent car at invalid index 10..." << endl;
    testSystem.rentCar(10);
    
    // Test 8: Return Car That's Not Rented
    cout << "\n--- TEST 8: Return Available Car ---" << endl;
    cout << "Trying to return car that's not rented..." << endl;
    testSystem.returnCar(0);
    
    // Test 9: Final System State
    cout << "\n--- TEST 9: Final System State ---" << endl;
    testSystem.displayAvailableCars();
    testSystem.displayRentedCars();
    testSystem.displayStats();
    
    cout << "\n=== ALL TESTS COMPLETED ===" << endl;
}

// Specific scenario tests
void runScenarioTests() {
    cout << "\n\n=== RUNNING SCENARIO TESTS ===" << endl;
    
    RentalSystem scenarioSystem;
    
    // Scenario 1: Student rents car for weekend
    cout << "\n--- SCENARIO 1: Weekend Rental ---" << endl;
    cout << "Student rents Ford Focus for the weekend..." << endl;
    scenarioSystem.rentCar(2);
    scenarioSystem.displayRentedCars();
    
    // Scenario 2: Group rents SUV for trip
    cout << "\n--- SCENARIO 2: Group Trip ---" << endl;
    cout << "Group rents Toyota RAV4 for road trip..." << endl;
    scenarioSystem.rentCar(4);
    
    // Scenario 3: Late return with fees
    cout << "\n--- SCENARIO 3: Late Returns ---" << endl;
    cout << "Returning Ford Focus 2 days late..." << endl;
    scenarioSystem.returnCar(2, 2);
    
    cout << "Returning Toyota RAV4 on time..." << endl;
    scenarioSystem.returnCar(4, 0);
    
    // Final revenue check
    cout << "\n--- FINAL REVENUE ---" << endl;
    scenarioSystem.displayStats();
}

void runEdgeCaseTests() {
    cout << "\n\n=== RUNNING EDGE CASE TESTS ===" << endl;
    
    RentalSystem edgeSystem;
    
    // Edge Case 1: Negative index
    cout << "\n--- EDGE CASE 1: Negative Index ---" << endl;
    edgeSystem.rentCar(-1);
    
    // Edge Case 2: Zero days late
    cout << "\n--- EDGE CASE 2: Zero Days Late ---" << endl;
    edgeSystem.rentCar(0);
    edgeSystem.returnCar(0, 0);
    
    // Edge Case 3: Multiple rentals and returns
    cout << "\n--- EDGE CASE 3: Multiple Operations ---" << endl;
    edgeSystem.rentCar(1);
    edgeSystem.rentCar(2);
    edgeSystem.returnCar(1);
    edgeSystem.rentCar(3);
    edgeSystem.returnCar(2);
    edgeSystem.returnCar(3);
    
    edgeSystem.displayStats();
}

int main() {
    runTests();
    runScenarioTests(); 
    runEdgeCaseTests();
    return 0;
}
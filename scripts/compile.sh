#!/bin/bash
echo "Compiling Campus Car Rental Test Suite..."
cd src
g++ -c vehicle.cpp rentalsystem.cpp test.cpp
g++ vehicle.o rentalsystem.o test.o -o ../campus_test
echo "Compilation complete! Run ./campus_test"
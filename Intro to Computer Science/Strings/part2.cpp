// Lab 9 Part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// print a histogram that shows the miles of coastline for various states.
// The input data is contained in the data file, coastline.dat and contains
//the name of a state on one line (you may assume no spaces in the name), and the miles of coastline
//on the next line.  A histogram is created by printing the number of stars equal to miles of coastline but  every star equal to 1000 miles
//You may assume that there is data in the file for 23 states (the others don't have any coastline!)
//

#include <iostream>
#include <string>
#include <fstream>
//prototype
void histogram(std::string state, int mileage);

int main()
{
    std::string state;
    int mileage;
    std::ifstream input ("coastline.dat");
    while (!input.eof())
    {
        input >> state >> mileage;
        histogram(state, mileage);
    }
    
}

//definition
void histogram(std::string state, int mileage)
{
    std::cout << state << std::endl;
    for (int i = 0; i < mileage / 1000; i++)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}

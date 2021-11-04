// Lab9 part 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// function named indoorDiningCapacity.
// takes two parameters, a string and an integer.
// If the string is "NYC" or "NJ" the function returns 25% of the second parameter. Otherwise the function returns 50% of the second parameter.

#include <iostream>
#include <string>
//prototype
int indoorDiningCapacity(std::string state, int capacity);

int main()
{
    std::string state;
    int capacity;
    std::cout << "Please enter the location: " << std::endl;
    std::cin >> state;
    std::cout << "Please enter the normal indoor dining capacity: " << std::endl;
    std::cin >> capacity;
    std::cout << indoorDiningCapacity(state, capacity); //function call
}
//definition
int indoorDiningCapacity(std::string state, int capacity)
{
    if (state == "NYC")
        return (capacity / 4);
    else if (state == "NJ")
        return (capacity / 4);
    else
        return (capacity / 2);
}

// ExtraCredit2.cpp : Crazy Pet Store.


#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    ofstream beforeEat;
    beforeEat.open("Before_Eat.txt");

    ofstream AfterEat;
    AfterEat.open("After_Eat.txt");

    int bowl = 0, goldFishCount = 0, guppyCount = 0, angelFishCount = 0, tigerFishCount = 0, fishEaten = 0, i = 1;;
    int fishLeft = 361;
    int numFish[] = { 15, 15, 15, 8, 8, 8, 8, 19, 16, 16, 16, 16, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 31, 31, 9, 9, 9, 9, 9, 26, 26, 26, 26, 8, 8 };
    string typeFish[] = { "Goldfish","Goldfish","Goldfish","Goldfish","Goldfish","Goldfish","Guppies","Guppies","Guppies","Guppies","Guppies","Guppies","Guppies","Angel Fish","Angel Fish","Angel Fish","Angel Fish","Angel Fish","Angel Fish","Angel Fish","Angel Fish","Angel Fish","Goldfish","Goldfish","Goldfish","Goldfish","Goldfish","Goldfish","Goldfish","Goldfish","Tiger Fish","Tiger Fish","Tiger Fish","Tiger Fish","Tiger Fish", };
    // Number and Type of fish in each bowl
   
    for (int x = 0; x <= 34; x++)
    {
        beforeEat << "There are " << numFish[x] << " " << typeFish[x] << " in bowl " << x + 1 << std::endl;
    }
  
    // Total number of each fish type

    for (int x = 0; x <= 35; x++)
    {
        if (typeFish[x] == "Goldfish")
            goldFishCount += numFish[x];
        else if (typeFish[x] == "Guppies")
            guppyCount += numFish[x];
        else if (typeFish[x] == "Angel Fish")
            angelFishCount += numFish[x];
        else if (typeFish[x] == "Tiger Fish")
            tigerFishCount += numFish[x];
    }
    
    if (beforeEat.is_open())
    {
        beforeEat << "There are " << goldFishCount << " Goldfish." << std::endl << "There are " << guppyCount << " Guppies." << std::endl << "There are " << angelFishCount << " Angel Fish." << std::endl << "There are " << tigerFishCount << " Tiger Fish." << std::endl  << "There are " << goldFishCount + guppyCount + angelFishCount + tigerFishCount << " total fish." << std::endl;
    }
    
    while (fishEaten < 361)
    {
        if (bowl > 35)
        {
            bowl = 0;
        }
        if (numFish[bowl] > 0)
        {
            if (i == 4)
            {
                fishEaten++;
                numFish[bowl]--;
                i = 1;
                bowl++;
            }
            else
            {
                i++;
                bowl++;
            }

        }
        else
        {
            bowl++;
        }
    }
    
    for (int x = 0; x <= 34; x++)
    {
        AfterEat << "After the seal eats, there are " << numFish[x] << " " << typeFish[x] << " in bowl " << x + 1 << std::endl;
    }
    goldFishCount = 0, guppyCount = 0, angelFishCount = 0, tigerFishCount = 0;

    for (int x = 0; x <= 35; x++)
    {
        if (typeFish[x] == "Goldfish")
            goldFishCount += numFish[x];
        else if (typeFish[x] == "Guppies")
            guppyCount += numFish[x];
        else if (typeFish[x] == "Angel Fish")
            angelFishCount += numFish[x];
        else if (typeFish[x] == "Tiger Fish")
            tigerFishCount += numFish[x];
    }

    AfterEat << "There are " << goldFishCount << " Goldfish left." << std::endl << "There are " << guppyCount << " Guppies left." << std::endl << "There are " << angelFishCount << " Angel Fish left." << std::endl << "There are " << tigerFishCount << " Tiger Fish left." << std::endl;
    AfterEat << "There are " << goldFishCount + guppyCount + angelFishCount + tigerFishCount << " total fish left.";

}

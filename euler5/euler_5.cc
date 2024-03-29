/**
 *        @file: euler_5.cc
 *      @author: Parker Corbitt
 *        @date: March 17, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/// function prototypes

/**
 * @brief checks if every number between 1 and 20 (inclusive) can go evenly into 'number'
 * 
 * @param number the number to be checked
 */
bool isAllMultiple(long number);

int main(int argc, char const *argv[])
{
    long number = 20;
    while(isAllMultiple(number) == false)
    {
        number++;
    }

    cout << number;
    return 0;
} // main

bool isAllMultiple(long number)
{
    for (int i = 1; i <= 20; i++)
    {
        if(number % i != 0)
        {
            return false;
        }
    }

    return true;
}
/**
 *        @file: euler_9.cc
 *      @author: Parker Corbitt
 *        @date: March 23, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/// function prototypes

bool is_triple(int a, int b, int c);

int main(int argc, char const *argv[])
{
    
    return 0;
} // main

bool is_triple(int a, int b, int c)
{
    int asq = a * a;
    int bsq = b * b;
    int csq = c * c;

    if(csq == (asq + bsq))
    {
        return true;
    }

    return false;
}
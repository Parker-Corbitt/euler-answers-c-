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

bool generate_triple(int n, int m);
int product = 0;

int main(int argc, char const *argv[])
{
    for(int n = 0; n < 33; n++)
    {
        for(int m = 0; m < 33;m++)
        {
            if(generate_triple(n, m) == true)
            {
                cout << product << endl;
                break;
            }
        }
    }
    return 0;

} // main

bool generate_triple(int n, int m)
{
    int a, b, c;

    a = (m * m) - (n * n);
    b = 2 * n * m;
    c = (n * n) + (m * m);

    int total = a + b + c;
    if(total == 1000)
    {
        product = a * b * c;
        return true;
    }

    return false;
}
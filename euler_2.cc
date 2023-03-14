/**
 *        @file: euler_2.cc
 *      @author: Parker Corbitt
 *        @date: March 13, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/// function prototypes

int main(int argc, char const *argv[])
{
    int total = 0;
    int first = 1;
    int second = 1;
    int tmp = 0;
    while (total < 4000000)
    {
        if (second % 2 == 0)
        {
            total += second;
        }
        tmp = second;
        second += first;
        first = tmp;
    }
    cout << total;
    return 0;
} // main
/*
 *        @file: multiples.cc
 *      @author: Parker Corbitt
 *        @date: March 07, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <omp.h>
using namespace std;

/// function prototypes

int main(int argc, char const *argv[])
{
    int sum = 0;

    for (int i = 0; i < 1000; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }

    cout << sum << endl;

//I was playing around with multithreading here. The below runs significantly slower, and I have a feeling it has to do with
//the overhead of creating threads, waiting for them all to do things individually, and then closing them. Premature parallelization
//is the root of all evil as Dr. Ostermann says

/** sum = 0;
#pragma omp parallel for
    for (int i = 0; i < 100000000; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))  
        {
#pragma omp critical
            sum += i;
        }
    }
    cout << sum << endl;**/
    return 0;
} // main
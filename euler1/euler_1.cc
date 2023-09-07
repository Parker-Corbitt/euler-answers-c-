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
    long sum = 0;

    for (int i = 0; i < 10000; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }

    cout << sum << endl;

//I was playing around with multithreading here. I have successfully made it to where
//this runs pretty much just as fast as the sequential version, but when scaled it
//runs a good deal faster.

    // long x[8];
    // for(int i = 0; i < 8; i++)
    // {
    //     x[i] = 0;
    // }

    // #pragma omp parallel for num_threads (8)
    // for (int i = 0; i < 100000; i++)
    // {
    //     if ((i % 3 == 0) || (i % 5 == 0))  
    //     {
    //         x[omp_get_thread_num()] += i;
    //     }
    // }

    // for(int i = 0; i < 8; i++)
    // {
    //     sum += x[i];
    // }
    // cout << sum << endl;
    return 0;
} // main
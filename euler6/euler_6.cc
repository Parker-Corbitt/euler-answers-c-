/**
 *        @file: euler_6.cc
 *      @author: Parker Corbitt
 *        @date: March 17, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <omp.h>
using namespace std;

/// function prototypes

/**
 * @brief determines if number is prime through use of mod operator
 * 
 * @param j the number to be checked
 * @return true - is prime
 * @return false - is not prime
 */
bool is_prime(long long j);

int main(int argc, char const *argv[])
{

    int index = 0;
    long long number = 1;
    vector<int> primes = {100001};

    while (index <= 10000)
    {
        if (is_prime(number))
        {
            primes.push_back(number);
            index++;
        }
        number++;
    }
    while (is_prime(number) == false)
    {
        number++;
    }
    primes.push_back(number);

    cout << "The 10001st prime number is " << primes[10001];

    return 0;
} // main

bool is_prime(long long j)
{
    if(j == 0 || j == 1)                            //0 and 1 are not prime
    {
        return false;
    }
    if (j >= 2)
    {
        for (int i = 2; i <= (j / 2); i++)
        {
            if (j % i == 0)
            {
                return false;                       //if it has a factor here, its not prime
            }
        }
    }
    return true;                                    //its prime
}
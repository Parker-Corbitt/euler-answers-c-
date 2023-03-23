/**
 *        @file: euler3.cc
 *      @author: Parker Corbitt
 *        @date: March 13, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/// function prototypes

long long largestFactor = 0;

/**
 * @brief checks if 'j' is a factor of 'number'
 */
void check_factor(long long number, long long j);

/**
 * @brief checks if 'j' is a prime  number
 */
bool is_prime(long long j);

int main(int argc, char const *argv[])
{
    
    long long number = 0;
    cout << "Enter the number to find its largest prime factor" << endl;
    cin >> number;

    long long j = 2;
    while(j <= (number / 2))
    {
        check_factor(number, j);
        j++;
    }
    if(largestFactor == 0)
    {
        largestFactor = number;
    }
    cout << largestFactor << endl;
    return 0;
}

void check_factor(long long number, long long j)
{
    if(number % j == 0)
    {
        if((j > largestFactor) && (is_prime(j)))
        {
            largestFactor = j;
        }
    }
}

bool is_prime(long long j)
{
    if(j >= 2)
    {
        for(int i = 2; i <= (j / 2); i++)
        {
            if(j % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

//600851475143 is the number project Euler tests with.
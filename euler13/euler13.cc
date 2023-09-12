/**
 *        @file: euler13.cc
 *      @author: Parker Corbitt
 *        @date: September 03, 2023
 *       @brief: This program is designed to add together the list of numbers provided in numbers.txt. I use the boost
 *                  library here, as no basic type allows for 50 digit numbers.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

/// function prototypes

/**
 * @brief loads the numbers stored in the specified ifstream into the set array
 * 
 * @param set - an array of 256 byte unsigned integers, capable of holding the required 50 digit numbers
 * @param instream - a file reader that is used to load the list of numbers.
 */
void load_numbers(uint256_t (&set)[100], ifstream &instream);

/**
 * @brief adds all numbers within the set array
 * 
 * @param set - contains the list of numbers from the numbers.txt file
 * @param sum - the sum of all numbers within the set array
 */
void add_numbers(uint256_t (&set)[100], uint256_t &sum);

int main(int argc, char const *argv[])
{

    ifstream instream;
    instream.open("numbers.txt");
    {
        if (instream.fail())
        {
            cout << "Error in opening file. Please verify numbers.txt exists." << endl;
            return 0;
        }
    }

    uint256_t set[100];
    uint256_t sum = 0;

    load_numbers(set, instream);
    add_numbers(set, sum);

    cout << "The total sum is " << sum << endl;
    string sum_string{sum.str()};
    cout << "The first 10 digits of the sum are  " << sum_string.substr(0, 10) << endl;

    return 0;
} // main

void load_numbers(uint256_t (&set)[100], ifstream &instream)
{
    string numbers[100];
    uint256_t x;
    int i = 0;
    while (!instream.eof())
    {
        getline(instream, numbers[i]);
        x = boost::lexical_cast<uint256_t>(numbers[i]);             //the boost equivalent of stoi(), but for extremely large numbers
        set[i] = x;
        i++;
    }
}

void add_numbers(uint256_t (&set)[100], uint256_t &sum)
{
    for (int i = 0; i < 100; i++)
    {
        sum += set[i];
    }
}
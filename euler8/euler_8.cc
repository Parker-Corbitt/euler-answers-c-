/**
 *        @file: euler_7.cc
 *      @author: Parker Corbitt
 *        @date: March 17, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

/// function prototypes

/**
 * @brief Takes the number in the number_string.txt file and loads each individual digit into a vector
 * 
 * @param number the string loaded from the number_string.txt file
 * @param digits the vector in which each individual digit is stored
 */
void load_number(string &number, vector<int> &digits);

/**
 * @brief Computes the number found by multiplying 13 consecutive digits
 * 
 * @param number the string loaded from the number_string.txt file
 * @param digits the vectoor  in which each individual digit is stored
 */
void product(string &number, vector<int> &digits);

long long LARGEST_PRODUCT = 0;

int main(int argc, char const *argv[])
{
    vector<int> digits;
    string number;
    load_number(number, digits);
    product(number, digits);

    cout << "The largest product of 13 consecutive numbers in the file 'number_string.txt' is "
         << LARGEST_PRODUCT << endl;

    return 0;
} // main

void load_number(string &number, vector<int> &digits)
{
    ifstream instream;
    instream.open("number_string.txt");
    if (instream.fail())
    {
        cout << "ERROR: Could not open file, please verify the file exists." << endl;
        return;
    }

    instream >> number;

    int j = number.size();

    for (int i = 0; i < j; i++)
    {
        char x = number[i];             //Converts the individual index of the string to an int
        int y = x - 48;
        digits.push_back(y);            //adds digit to vector in order
    }
}

void product(string &number, vector<int> &digits)
{
    int i = 0;
    long long tempProduct = 1;
    int numberSize = number.size() - 14;
    while (i < numberSize)                      //limits to 13 before the size of the string
    {
        tempProduct = 1;

        for (int j = i; j < (i + 13); j++)      //the computation of the product
        {
            tempProduct *= digits[j];
        }

        if (tempProduct > LARGEST_PRODUCT)      //comaprison of previous products
        {
            LARGEST_PRODUCT = tempProduct;
        }
        i++;
    }
}
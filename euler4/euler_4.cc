/**
 *        @file: euler_4.cc
 *      @author: Parker Corbitt
 *        @date: March 17, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

/// function prototypes

bool isPalindrome(int number);
int LARGEST_PALINDROME = 0;

int main(int argc, char const *argv[])
{

    for (int i = 999; i >= 100; i--)
    {
        for (int j = 999; j >= 100; j--)
        {
            int number = i * j;
            if(isPalindrome(number) == true && number > LARGEST_PALINDROME)
            {
                LARGEST_PALINDROME = number;
            }
        }
    }
    cout << "The Largest Palindrome that was found for 3 digit numbers is " << LARGEST_PALINDROME << endl;
    return 0;
} // main

bool isPalindrome(int number)
{
    string x = to_string(number);
    string y;
    for (int i = x.size() - 1; i >= 0; i--)
    {
        y += x[i];
    }

    if (x == y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
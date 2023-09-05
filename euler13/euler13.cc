/**
 *        @file: euler13.cc
 *      @author: Parker Corbitt
 *        @date: September 03, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

///function prototypes
void load_numbers(long long (&set)[100], ifstream &instream);

int main(int argc, char const *argv[]) {

    ifstream instream;
    instream.open("numbers.txt");
    {
        boost::multiprecision
        if(instream.fail())
        {
            cout << "Error in opening file. Please verify numbers.txt exists." << endl;
            return 0;
        }
    }

    long long set[100];
    load_numbers(set, instream);
    return 0;
}// main

void load_numbers(long long (&set)[100], ifstream &instream)
{
    string number;
    int x;
    int i = 0;
    while(!instream.eof())
    {
        getline(instream, number);
        x = stoll(number);
        set[i] = x;
        i++;
    }
}
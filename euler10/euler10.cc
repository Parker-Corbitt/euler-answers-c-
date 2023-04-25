/**
 *        @file: euler10.cc
 *      @author: Parker Corbitt
 *        @date: April 24, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <omp.h>
using namespace std;

///function prototypes

struct index
{
    int number = 0;
    bool prime = true;
};

vector<index> list;

void fill_list(vector<index> &list, int limit);
void mark_composite(vector<index> &list, int limit, int n);
int  idx_nxt_prime(vector<index> &list, int limit, int n);
long sum_all_primes(vector<index> &list, int limit);

int main(int argc, char const *argv[]) {

    string tmp = argv[1];

    //Since the first prime number is 2, two will be at index 0. Therefore, the limit of primes will be at the index 2 below the number. Fix  this comment later
    int limit = stoi(tmp) - 2;

    int n = 2;
    int index_n = n - 2;

    fill_list(list, limit);


    //debugging for fill_list.
    /**for(int i = 0; i < limit; i++)
    {
        cout << list[i].number;
    }**/
    while(n != limit)
    {
        mark_composite(list, limit, n);
        n = idx_nxt_prime(list, limit, n);
        if(n == -1)
        {
            break;
        }
    }

    /**for(int i = 0; i < limit; i++)
    {
        if(list[i].prime == true)
        {
            cout << list[i].number << endl;
        }
    }**/

    long total = sum_all_primes(list, limit);
    
    cout << "The sum of all primes below " << limit + 2 << " is " << total << endl;

    return 0;
}// main

void fill_list(vector<index> &list, int limit)
{   
    index a;
    int starting_number = 2;
    for(int i = 0; i < limit; i++)
    {
        a.number = starting_number;
        list.push_back(a);
        starting_number++;
    }
}

void mark_composite(vector<index> &list, int limit, int n)
{
    #pragma omp parallel for
    for(int i = 0; i < limit; i++)
    {
        if(list[i].number % n == 0 && list[i].number != n)
        {
            list[i].prime = false;
        }
    }
}

int idx_nxt_prime(vector<index> &list, int limit, int n)
{
    for(int i = n - 1; i < limit; i++)
    {
        if(list[i].prime == true)
        {
            return list[i].number;
        }
    }

    return -1;
}

long sum_all_primes(vector<index> &list, int limit)
{
    long sum = 0;
    for(int i = 0; i < limit; i++)
    {
        if(list[i].prime == true)
        {
            sum += list[i].number;
        }
    }

    return sum;
}

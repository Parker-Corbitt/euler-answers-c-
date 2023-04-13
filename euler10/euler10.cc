/**
 *        @file: euler10.cc
 *      @author: Parker Corbitt
 *        @date: April 10, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <omp.h>
using namespace std;

///function prototypes

struct is_prime
{
    int number = 0;
    bool prime = true;
};

vector<is_prime> number_list;
long int sum = 0;

void fill_number_list(int limit);
void Sieve_E();
void add_all_primes();

int main(int argc, char const *argv[]) {

    int limit = 200000;

    fill_number_list(limit);
    Sieve_E();
    add_all_primes();
    cout << sum << endl;
    
    return 0;
}// main


void fill_number_list(int limit)
{
    cout << "filling the list" << endl;
      //  1 and 0 shouldn't be considered;
    for(int i = 2; i < limit; i++)
    {
        is_prime iteration;
        iteration.number = i;
        number_list.push_back(iteration);
    }

}

void Sieve_E()
{
    cout << "doing the sieve..." << endl;
    int p = 2;
    int p_limit = number_list.size() / 2;
    while(p != p_limit)
    {
        #pragma omp parallel for num_threads(16)
        for(int i = 0; i < number_list.size(); i++)
        {
            if(number_list[i].number % p == 0 && number_list[i].prime == true)
            {
                number_list[i].prime == false;
                
            }
            
        }
        p++;
    }

}

void add_all_primes()
{
    cout << "adding..." << endl;
    for(int i = 0; i < number_list.size(); i++)
    {
        if(number_list[i].prime  == true)
        {
            sum += number_list[i].number;
        }
    }
}
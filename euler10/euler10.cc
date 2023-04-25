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

//Throughout this program will be an analysis of why this is so much slower than the bitset solution. 


/**
 * Here is my first mistake. I didn't think to look into better possible data structures before starting
 * this project. While I didn't know about the bitset data type, I should have researched before starting
 * this project. I only started looking into things after I found out that it was slow (which is still better than nothing)
 */
struct index
{
    int number = 0;
    bool prime = true;
};

//Using a vector is going to add a lot of overhead, when it's not necessary.
vector<index> list;

///function prototypes
void fill_list(vector<index> &list, int limit);
void mark_composite(vector<index> &list, int limit, int n);
int  idx_nxt_prime(vector<index> &list, int limit, int n);
long sum_all_primes(vector<index> &list, int limit);

int main(int argc, char const *argv[]) {

    string tmp = argv[1];

    //Since the first prime number is 2, two will be at index 0. Therefore, the limit of primes will be at the index 2 below the number. Fix  this comment later
    int limit = stoi(tmp) - 2;

    /**
     * This is unnecessarily hard to understand. It would have been easier to think about if I would have just started at 0, and marked them as not prime. 2 numbers out of 
     * 2 million isn't going to matter in the grand scheme of things
     */
    int n = 2;
    int index_n = n - 2;

    //with my chosen algorithm, this wasn't a bad idea.
    fill_list(list, limit);


    while(n != limit)
    {
        mark_composite(list, limit, n);
        n = idx_nxt_prime(list, limit, n);
        if(n == -1)
        {
            break;
        }
    }

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

/**the use of openmp here definitely helped the algorithm, but this section is written poorly.
 * First, mod is a more expensive operation than multiplication. It would have been more efficient
 * to mark composite the results of n * list[i]. The boolean comparison to n is unecessary as well, if 
 * I would have started checking the products at i = 2. This is almost certainly the most expensive part of the
 * program
 */
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

//This isn't bad. Honestly I'd say this was pretty good overall. 
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

//This was also pretty good. 
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

/**
 *        @file: euler11.cc
 *      @author: Parker Corbitt
 *        @date: June 16, 2023
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

/// function prototypes

int NUM_COLUMN = 19;

void load_vector(ifstream &input, vector<vector<int>> &grid);
void print_vector(vector<vector<int>> &grid);

int main(int argc, char const *argv[])
{

    vector<vector<int>> grid;

    ifstream input;
    input.open("grid.txt");
    if (input.fail())
    {
        cout << "Error in opening file \"grid.txt\", please verify the file exists" << endl;
        return 0;
    }

    load_vector(input, grid);
    print_vector(grid);

    return 0;
} // main

//************************************************************************************************

void load_vector(ifstream &input, vector<vector<int>> &grid)
{
    string tmp;

    while (!input.eof())
    {
        getline(input, tmp);
        stringstream splitter(tmp); // To split the line up into each individual value
        string number;              // This is for stoi() to populate the "value" variable
        int value;
        vector<int> tmp_list;

        while (splitter >> number)
        {
            value = stoi(number);
            tmp_list.push_back(value);
        }

        grid.push_back(tmp_list); // pushes the list onto the grid once finished
    }
}

void print_vector(vector<vector<int>> &grid)
{
    for (int i = 0; i < NUM_COLUMN; i++)
    {
        for (int j = 0; j < NUM_COLUMN; j++)
        {
            cout << setw(2) << setfill('0') << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int check_down(vector<vector<int>> &grid)
{
}

int check_ltor(vector<vector<int>> &grid)
{
}

int check_bl_to_tr(vector<vector<int>> &grid)
{
}

int check_br_to_tl(vector<vector<int>> &grid)
{
}
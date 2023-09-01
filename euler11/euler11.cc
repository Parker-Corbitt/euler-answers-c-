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
int check_down(vector<vector<int>> &grid);
int check_ltor(vector<vector<int>> &grid);
int check_bl_to_tr(vector<vector<int>> &grid);
int check_br_to_tl(vector<vector<int>> &grid);

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
    cout << '\n' << check_down(grid) << endl;
    cout << '\n' << check_ltor(grid) << endl;
    cout << '\n' << check_bl_to_tr(grid) << endl;
    cout << '\n' << check_br_to_tl(grid) << endl;

    return 0;
} // main

//************************************************************************************************

//The 2D vector should be structured as if i represents the rows and j the column
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
    int max = 0;
    for(int i = 0; i < grid.size() - 4; i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            int x = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
            if(x > max)
            {
                max = x;
            }
        }
    }
    return max;
}

int check_ltor(vector<vector<int>> &grid)
{
    int max = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size() - 4; j++)
        {
            int x = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
            if(x > max)
            {
                max = x;
            }
        }
    }
    return max;
}

int check_bl_to_tr(vector<vector<int>> &grid)
{
    int max  = 0;
    for(int i = grid.size() - 1; i >= 3; i--)
    {
        for(int j = 0; j < grid[i].size() - 4; j++)
        {
            int x = grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3];
            if(x > max)
            {
                max = x;
            }
        }
    }
    return max;
}

int check_br_to_tl(vector<vector<int>> &grid)
{
    int max  = 0;
    for(int i = grid.size() - 1; i >= 3; i--)
    {
        for(int j = grid[i].size() - 1; j > 0; j--)
        {
            int x = grid[i][j] * grid[i - 1][j - 1] * grid[i - 2][j - 2] * grid[i - 3][j - 3];
            if(x > max)
            {
                max = x;
            }
        }
    }
    return max;
}
//T02_G11

#include "Maze.h"
#include <iostream> 
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Maze::Maze(const string& path)
{
    
    vector <string> vec; //place where we will be storing all the lines

    ifstream file(path); //open file for read

    //insert maze in a vector
    getline(file, this->line);
    while (getline(file, this->line)) vec.push_back(this->line);

    for (auto & i : vec) cout << i << endl;
}


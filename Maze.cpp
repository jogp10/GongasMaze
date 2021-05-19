//T02_G11

#include "Maze.h"
#include <iostream> 
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Maze::Maze(unsigned int numRows, unsigned int numCols)
{
    this->numRows = numRows;
    this->numCols = numCols;
}

bool Maze::addPost(const Post& post, const Position& position)
{

}

unsigned int Maze::getnumRows() const
{
    return numRows;
}

unsigned int Maze::getnumCols() const
{
    return numCols;
}


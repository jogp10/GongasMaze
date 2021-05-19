//T02_G11

#include "Maze.h"
#include <iostream>

using namespace std;

Maze::Maze(unsigned int numRows, unsigned int numCols)
{
    this->numRows = numRows;
    this->numCols = numCols;
}

bool Maze::addPost(const Post& post, const Position& position)
{
    for(int i=0; i<posts.size(); i++)
    {
        if(post.getRow() == position.row && post.getCol() == position.col) return false;
    }
    return true;
}

void Maze::addPost(const Post& post)
{
    posts.push_back(post);
}

unsigned int Maze::getnumRows() const
{
    return numRows;
}

unsigned int Maze::getnumCols() const
{
    return numCols;
}

void Maze::show() const
{
    cout << "nRows: " << numRows << " nCols: " << numCols << endl;

}
//T02_G11

#include "Maze.h"
#include <iostream>

using namespace std;

Maze::Maze(unsigned int numRows, unsigned int numCols)
{
    this->numRows = numRows;
    this->numCols = numCols;
}

bool Maze::checkPost(const Post& post)
{
    for(int i=0; i<posts.size(); i++)
    {
        if(post.getRow() == posts[i].getRow() && post.getCol() == posts[i].getCol()) return false;
    }
    return true;
}

void Maze::addPost(const Post& post)
{
    if(Maze::checkPost(post)) posts.push_back(post);
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
    cout << "The maze has " << posts.size() << " posts" << endl;
}
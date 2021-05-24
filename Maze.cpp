//T02_G11

#include "Maze.h"
#include <iostream>

using namespace std;

Maze::Maze()
{

}

Maze::Maze(unsigned int numRows, unsigned int numCols)
{
    this->numRows = numRows;
    this->numCols = numCols;
}

void Maze::setCols(unsigned int numCols)
{
    this->numCols = numCols; 
}

void Maze::setRows(unsigned int numRows)
{
    this->numRows = numRows; 
} 

bool Maze::checkPost(Post& post) const
{
    for(int i=0; i<posts.size(); i++)
    {
        if(post.getRow() == posts[i].getRow() && post.getCol() == posts[i].getCol() && post.getSymbol() == posts[i].getSymbol()) 
        {
            return true;
        }
    }
    return false;
}

bool Maze::checkExit(Exit& exit) const
{
    for(int i=0; i<exits.size(); i++)
    {
        if(exit.Orow == exits[i].Orow && exit.Ocol == exits[i].Ocol)
        {
            return true;
        }
    }
    return false;
}

void Maze::addPost(const Post& post)
{
    posts.push_back(post);
}

void Maze::addExit(const Exit& exit)
{
    exits.push_back(exit);
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
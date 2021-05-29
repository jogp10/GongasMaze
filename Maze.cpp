//T02_G11

#include "Maze.h"

void Maze::setCols(unsigned int numCols)
{
    this->numCols = numCols; 
}

void Maze::setRows(unsigned int numRows)
{
    this->numRows = numRows; 
} 

bool Maze::checkPost(const Post& post) const
{
    for(auto i : posts)
    {
        if(post.getRow() == i.getRow()&& post.getCol() == i.getCol() && post.getElectric() == i.getElectric())
        {
            return true;
        }
    }
    return false;
}

bool Maze::checkExit(const Exit& exit) const
{
    for(auto i : exits)
    {
        if(exit.O_row == i.O_row && exit.O_col == i.O_col)
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
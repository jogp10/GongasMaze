//T02_G11
#ifndef T02_G11_MAZE_H
#define T02_G11_MAZE_H

#include "structs.h"
#include "exit.h"
#include "Post.h"
#include <iostream>
#include <vector>

using namespace std;

class Maze
{
public:
    //constructors
    Maze() = default;
    Maze(unsigned int numRows, unsigned int numCols);
    
    void setCols(unsigned int numCols); // set number of columns of Maze
    void setRows(unsigned int numRows); // set number of rows of Maze
    
    void addPost(const Post& post); // add post to vector of posts
    void addExit(const Exit& exit); // add exit to vector of exits

    bool checkPost(const Post& post) const; // check the existence of a post in vector posts
    bool checkExit(const Exit& exit) const; // check the existence of a exit in vector exits
    
    unsigned int getnumRows() const; // get the number of Rows of Maze
    unsigned int getnumCols() const; // get the number of Columns of Maze

    void show() const; // Mostly for testing the dimensions of Maze
    ~Maze() = default; // deConstructor

private:
    int numRows, numCols;
    vector<Post> posts;
    vector<Exit> exits;
};


#endif //T02_G11_MAZE_H

/*
Maze is made of Post. In Maze you have to call Post class.

This class is made to create and load the map (not sure of this). 
*/
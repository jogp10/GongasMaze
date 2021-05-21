//T02_G11
#ifndef T02_G11_MAZE_H
#define T02_G11_MAZE_H

#include "structs.h"
#include "Post.h"
#include <iostream>
#include <vector>

using namespace std;

class Maze
{
public:
    Maze(); 
    Maze(unsigned int numRows, unsigned int numCols);
    
    void setCols(unsigned int numCols); 
    void setRows(unsigned int numRows); 
    
    bool checkPost(const Post& post);
    void addPost(const Post& post);

    unsigned int getnumRows() const;
    unsigned int getnumCols() const;

    void show() const;

private:
    int numRows, numCols;
    vector<Post> posts;
};


#endif //T02_G11_MAZE_H

/*
Maze is made of Post. In Maze you have to call Post class.

This class is made to create and load the map (not sure of this). 
*/
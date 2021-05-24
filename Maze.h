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
    Maze(); 
    Maze(unsigned int numRows, unsigned int numCols);
    
    void setCols(unsigned int numCols); 
    void setRows(unsigned int numRows); 
    
    void addPost(const Post& post);
    void addExit(const Exit& exit);

    bool checkPost(Post& post) const;
    bool checkExit(Exit& exit) const;
    
    unsigned int getnumRows() const;
    unsigned int getnumCols() const;

    void show() const;

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
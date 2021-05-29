//T02_G11
#ifndef T02_G11_MAZE_H
#define T02_G11_MAZE_H

#include "exit.h"
#include "Post.h"
#include <vector>

class Maze
{
public:
    //constructors
    Maze() = default;
    
    void setCols(unsigned int numCols); // set number of columns of Maze
    void setRows(unsigned int numRows); // set number of rows of Maze
    
    void addPost(const Post& post); // add post to vector of posts
    void addExit(const Exit& exit); // add exit to vector of exits

    bool checkPost(const Post& post) const; // check the existence of a post in vector posts
    bool checkExit(const Exit& exit) const; // check the existence of a exit in vector exits
    
    unsigned int getnumRows() const; // get the number of Rows of Maze
    unsigned int getnumCols() const; // get the number of Columns of Maze

    ~Maze() = default; // deConstructor

private:
    unsigned int numRows=0, numCols=0;
    std::vector<Post> posts;
    std::vector<Exit> exits;
};


#endif //T02_G11_MAZE_H
//T02_G11
#ifndef T02_G11_MAZE_H
#define T02_G11_MAZE_H

#include <iostream>
#include <string>

using namespace std;

class Maze
{
public:
    Maze(const string& path);

private:
    string line;
    vector<Post> posts;
};


#endif //T02_G11_MAZE_H

/*
Maze is made of Post. In Maze you have to call Post class.

This class is made to create and load the map (not sure of this). 
*/
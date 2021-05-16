//T02_G11

#include "Maze.h"
#include "Post.h"
#include <iostream> 
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Maze::Maze(const string& path)
{
    ifstream file(path); //open file for read

    //insert maze in a vector
    getline(file, this->line);
    int y=0;
    while (getline(file, this->line))
    {
        for(int i=0; i<line.size(); i++)
        {
            if(line[i] == '*' || line[i] == '+')
            {
                Post post(y, i);
                if(line[i] == '*') post.setEletric(true);
                posts.push_back(post);
            }
        }
        y++;
    }
}


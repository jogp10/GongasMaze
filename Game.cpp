//T02_G11

#include "Game.h"
#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

Game::Game(const string & filename)
{
    Maze level; 
    int index = 0; bool temp = true; string col; string lin;  
    
    ifstream file(filename); 
    if (file.is_open())
    {
        getline(file, line); 

        for (int index = 0; index <= line.size(); index++)
        {
            if (line[index] == 'x' || line[index] == 'X')
            {
                level.setCols(strtoul(line.substr(0, index)));
                level.setRows(strtoul(line.substr(index+1, line.size()-index))); 

                break; 
            }
        }

        while (getline(file, line))
        {
            static int nLines = 0;  

            for (int i = 0; i<= line.size(); i++)
            {
                if (line[i] == '+' || line[i] == '*') // post or eletric post
                {
                    Post post(nLines, i, line[i]); 
                    level.addPost(post); 
                }

                else if (line[i] == 'R') // robot 
                {
                    Robot robot(nLines, i); 
                    robots.push_back(robot); 
                }

                else if (line[i] == 'H') // player
                {
                    Player player(nLines, i, line[i]) ; 
                }

                else if (line[i] == 'O') // hole 2 win
                {
                    
                }
            }

            nLines++; 

        }
    }
}
//T02_G11

#include "Game.h"
#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

Game::Game(const string & filename)
{
    Maze level; 
    int index = 0; bool temp = true; string col; string line;  
    
    ifstream file(filename); 
    if (file.is_open())
    {
        getline(file, line);
        int col, lines; char x;
        file >> col >> x >> lines;
        level.setCols(col); level.setRows(lines);

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
                    Player tplayer(nLines, i, line[i]);
                    player = tplayer;
                }

                else if (line[i] == 'O') // hole 2 win
                {
                    Exit exit;
                    exit.Ocol = i;
                    exit.Orow = nLines;
                    level.addExit(exit);
                }
            }
            cout << line << endl;
            nLines++; 
        }

    }
}
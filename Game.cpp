//T02_G11

#include <cassert>
#include "Game.h"
#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

Game::Game(const string & filename)
{   
    ifstream file(filename); 
    if (file.is_open())
    {

        // set dimension of maze
        string line; 
        getline(file, line);
        int col, lines; char x;
        file >> col >> x >> lines;
        maze.setCols(col); maze.setRows(lines);

        // scan maze
        while (getline(file, line))
        {
            static int nLines = 0;  

            for (int i = 0; i<= line.size(); i++)
            {
                if (line[i] == '+' || line[i] == '*') // post or eletric post
                {
                    Post post(nLines, i, line[i]); 
                    maze.addPost(post); 
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
                    assert(nLines == player.getRow());
                    assert(i == player.getCol());
                }

                else if (line[i] == 'O') // hole 2 win
                {
                    Exit exit;
                    exit.Ocol = i;
                    exit.Orow = nLines;
                    assert(exit.Ocol == i);
                    assert(exit.Orow == nLines);
                    maze.addExit(exit);
                }
            }
            cout << line << endl;
            nLines++; 
        }
    }
}

bool Game::play()
{

}

bool Game::isValid()
{

}

void Game::showGameDisplay() const
{
    for(int i=0; i<maze.getnumRows(); i++)
    {
        for(int j=0; j<maze.getnumCols(); j++)
        {
            if(player.getRow() == i && player.getCol() == j)
            {
                cout << player.getSymbol();
                break;
            }
            for(int w=0; w<robots.size(); w++)
            {
                if(robots[w].getRow() == i && robots[w].getCol() == j) 
                {
                    cout << robots[w].getSymbol();
                    break;
                }
            }
            for(int w=0;;)
            {
                if() cout << post.getSymbol();
            }
            for(int w=0;;)
            {
                if() cout << "O";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool Game::collide(Robot& robot, Post& post)
{

}

bool Game::collide(Robot& robot, Player& player)
{

}
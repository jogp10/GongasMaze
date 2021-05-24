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
    if(player.getLive())
    {
        char play;
        string check = "QWEASDZXC"; //possible plays
        Movement mov;

        // ask for a play
        cout << "What's your play" << endl;

        while(true){
            cin >> play;
            if (cin.eof()) {
                //exitGame = true;
                return true;
            }
            if(!cin.fail()) {
                cin.ignore(10000, '\n');
                if (check.find((char) toupper(play)) != string::npos) break;
            }
            else {
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        switch(toupper(play))
        {
            case 'W':
                mov = {-1, 0};
                break;
            case 'E':
                mov = {-1, 1};
                break;
            case 'D':
                mov = {0, 1};
                break;
            case 'C':
                mov = {1, 1};
                break;
            case 'X':
                mov = {1, 0};
                break;
            case 'Z':
                mov = {1, -1};
                break;
            case 'A':
                mov = {0, -1};
                break;
            case 'Q':
                mov = {-1, -1};
                break;
            default:
                mov = {0, 0};
        }
        if(Game::isValid(mov)) player.setMove(mov);
        Exit exit = {player.getRow(), player.getCol()};
        if(maze.checkExit(exit))


    }
}

bool Game::isValid(Movement& movement)
{
    int i, j;
    i = player.getRow() + movement.dRow;
    j = player.getCol() + movement.dCol;

    for(int w=0; w<robots.size(); w++)
    {
        if(robots[w].getRow() == i && robots[w].getCol() == j) 
        {
            return false;
        }
    }

    Post post(i, j, '+');
    if(maze.checkPost(post)) 
    {
        return false;
    }
    else
    {
        Post post(i, j, '*');
        if(maze.checkPost(post))
        {
            return false;
        }
    }
    return true;
}

void Game::showGameDisplay() const
{
    for(int i=0; i<maze.getnumRows(); i++)
    {
        for(int j=0; j<maze.getnumCols(); j++)
        {
            bool stop = false;
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
                    stop = true;
                    break;
                }
            }
            if(stop) break;

            Post post(i, j, '+');
            if(maze.checkPost(post)) 
            {
                cout << '+';
                break;
            }
            else
            {
                Post post(i, j, '*');
                if(maze.checkPost(post))
                {
                    cout << '*';
                    break;
                }
            }

            Exit exit = {i, j};
            if(maze.checkExit(exit))
            {
                cout << "O";
                break;
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Game::collide(Robot& robot, Post& post)
{
    if(post.getRow() == robot.getRow() && post.getCol() == robot.getCol())
    {
        robot.setDead();
        return true;
    }
    return false;
}

bool Game::collide(Robot& robot)
{
    if(robot.getRow() == player.getRow() && robot.getCol() == player.getCol())
    {
        player.setDead();
        return true;
    }
    return false;
}

bool Game::collide(Robot& robot, Robot& robot2)
{
    if(robot.getRow() == robot2.getRow() && robot.getCol() == robot2.getCol())
    {
        robot.setDead();
        robot2.setDead();
    }

}
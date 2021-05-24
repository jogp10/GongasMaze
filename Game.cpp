//T02_G11

#include <cassert>
#include "Game.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Game::Game(const string & filename)
{   
    ifstream file(filename); 
    if (file.is_open())
    {

        // set dimension of maze
        string line; 
        int col, lines; char x;
        file >> col >> x >> lines;
        maze.setCols(col); maze.setRows(lines);

        // scan maze
        getline(file, line);
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
                    this->player = tplayer;
                    assert(nLines == this->player.getRow());
                    assert(i == this->player.getCol());
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
    while(true)
    {
        if(!player.getLive()) return false;
        char play;
        string check = "QWEASDZXC"; //possible plays
        Movement mov;

        // ask for a play
        cout << "What's your play" << endl;

        while(true)
        {
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
        else
        {
            cout << "Invalid play!" << endl;
            continue;
        }
        Exit exit = {player.getRow(), player.getCol()};
        if(maze.checkExit(exit))
        {
            return true;
        }

        //robots turn
        for (int i= 0; i <= robots.size(); i++)
        {
            int rowP, colP, rowR, colR, indice = 0; 
            
            rowP = player.getRow(); 
            colP = player.getCol();
            rowR = robots[i].getRow(); 
            colR = robots[i].getCol();

            double q,w,e,a,d,z,x,c, minor = 999999;
            vector<double> minor_d;

            //case 0
            q = sqrt((pow(colP-(colR-1), 2) + pow(rowP - (rowR-1), 2))); minor_d.push_back(q);
            //case 1
            w = sqrt((pow(colP-colR, 2) + pow(rowP - (rowR-1), 2))); minor_d.push_back(w);
            //case 2
            e = sqrt((pow(colP-(colR+1), 2) + pow(rowP - (rowR-1), 2))); minor_d.push_back(e);
            //case 3
            a = sqrt((pow(colP-(colR-1), 2) + pow(rowP - rowR, 2))); minor_d.push_back(a);
            //case 4
            d = sqrt((pow(colP-(colR+1), 2) + pow(rowP - rowR, 2))); minor_d.push_back(d);
            //case 5
            z = sqrt((pow(colP-(colR-1), 2) + pow(rowP - (rowR+1), 2))); minor_d.push_back(z);
            //case 6
            x = sqrt((pow(colP-colR, 2) + pow(rowP - (rowR+1), 2))); minor_d.push_back(x);
            //case 7
            c = sqrt((pow(colP-(colR+1), 2) + pow(rowP - (rowR+1), 2))); minor_d.push_back(c);

            for(int j=0; j<=7; j++)
            {
                if (minor_d[j] <= minor) // see which distance is minor
                {
                    minor = minor_d[j];
                    indice = j;
                }
            }

            Movement mov; // mov(row, col)

            switch(indice)
            {
                case 0:  // Q
                    mov = {-1,-1};
                case 1: // W
                    mov = {0, -1};
                case 2: // E
                    mov = {-1, 1}; 
                case 3:  // A 
                   mov = {0,-1}; 
                case 4: // D
                    mov = {0,1}; 
                case 5: // Z
                    mov = {1,-1}; 
                case 6:  // X
                    mov = {0,1}; 
                case 7: // C
                    mov = {1,1}; 
                default: 
                    mov = {0,0}; 
                
            }

            robots[i].setMove(mov); 

            Game::collide(robots[i]); 

        }

        Game::showGameDisplay(); 

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
                continue;
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
            if(stop) continue;

            Post post(i, j, '+');
            if(maze.checkPost(post)) 
            {
                cout << '+';
                continue;
            }
            else
            {
                Post post(i, j, '*');
                if(maze.checkPost(post))
                {
                    cout << '*';
                    continue;
                }
            }

            Exit exit = {i, j};
            if(maze.checkExit(exit))
            {
                cout << "O";
                continue;
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
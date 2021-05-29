//T02_G11

#include "Game.h"
#include <iostream> 
#include <fstream>
#include <cmath>

using namespace std;

Game::Game(const string & filename)
{   
    ifstream file(filename); 
    if (file.is_open()) // operations to follow if file is open 
    {

        // set dimension of maze
        string line; 
        int col, lines; char x;
        file >> lines >> x >> col;
        maze.setCols(col); maze.setRows(lines);

        // scan maze
        getline(file, line);
        int nLines = 0;
        while (getline(file, line))
        {
            for (int i = 0; i<= line.size(); i++)
            {
                if (line[i] == '+' || line[i] == '*') // post or electric post
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
                    player.setRow(nLines);
                    player.setCol(i);
                    player.setSymbol(line[i]);
                }

                else if (line[i] == 'O') // hole 2 win
                {
                    Exit exit = {(unsigned int) nLines, (unsigned int) i};
                    maze.addExit(exit);
                }
            }
            cout << line << endl;  // output line
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
        string check = "QWEASDZXC"; // string containing all possible plays
        Movement mov = {0, 0};

        // ask for a play
        cout << "What's your play" << endl;

        while(true)
        {
            cin >> play;
            if (cin.eof()) {
                //exitGame = true;
                return false;
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
        if(maze.checkExit(exit)) {
            Game::showGameDisplay();
            return true;
        }
        Post post(player.getRow(), player.getCol(), '*');
        if(maze.checkPost(post))
        {
            Game::collide<Player>(player, post, mov);
        }
        
        Game::robots_turn(); //robots turn
        
        Game::showGameDisplay();
    }
}

void Game::robots_turn()
{
    for (auto & robot : robots)
    {
        if(robot.getLive()){
            int rowP, colP, rowR, colR, indice = 0;
            
            rowP = (int) player.getRow();
            colP = (int) player.getCol();
            rowR = (int) robot.getRow();
            colR = (int) robot.getCol();

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

            Movement mov={0, 0}; // mov(row, col)

            switch(indice)
            {
                case 0:  // Q
                    mov = {-1,-1};
                    break;
                case 1: // W
                    mov = {-1, 0};
                    break;
                case 2: // E
                    mov = {-1, 1};
                    break; 
                case 3:  // A 
                    mov = {0,-1};
                    break; 
                case 4: // D
                    mov = {0,1};
                    break; 
                case 5: // Z
                    mov = {1,-1}; 
                    break;
                case 6:  // X
                    mov = {1,0}; 
                    break;
                case 7: // C
                    mov = {1,1}; 
                    break;
                default:
                    break;
            }
            robot.setMove(mov);
            Game::checkCollide(robot, mov);
        }
    }
}


bool Game::isValid(Movement& movement)
{
    unsigned int i, j;
    i = player.getRow() + movement.dRow;
    j = player.getCol() + movement.dCol;

    for(auto & robot : robots)
    {
        if(robot.getRow() == i && robot.getCol() == j)
        {
            return false;
        }
    }

    Post post(i, j, '+');
    if(maze.checkPost(post)) return false;
    return true;
}

void Game::showGameDisplay() const
{
    for(unsigned int i=0; i<maze.getnumRows(); i++)
    {
        for(unsigned int j=0; j<maze.getnumCols(); j++)
        {
            bool stop = false;
            if(player.getRow() == i && player.getCol() == j)
            {
                cout << player.getSymbol();
                continue;
            }

            for(auto robot : robots)
            {
                if(robot.getRow() == i && robot.getCol() == j)
                {
                    cout << robot.getSymbol();
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
                post.setSymbol('*');
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

bool Game::checkCollide(Robot& robot, Movement& movement)
{
    if(robot.getRow() == player.getRow() && robot.getCol() == player.getCol()) return Game::collide(robot, player);
    for(auto & i : robots)
    {
        if(robot.getRow() == i.getRow() && robot.getCol() == i.getCol() && robot.getId() != i.getId())
        {
            return Game::collide(robot, i);
        }
    }
    Post post(robot.getRow(), robot.getCol());
    if(maze.checkPost(post)) return Game::collide<Robot>(robot, post, movement);
    post.setSymbol('*');
    if(maze.checkPost(post)) return Game::collide<Robot>(robot, post, movement);
    return false;
}

template<typename T>
bool Game::collide(T& object, Post& post, Movement& movement)
{
    if(post.getSymbol() == '*')
    {
        movement.dCol = 0-movement.dCol; movement.dRow = 0-movement.dRow;
        object.setMove(movement);
    }
    object.setDead();
    return true;
}

bool Game::collide(Robot& robot, Player& player)
{
    player.setDead();
    return false;

}

bool Game::collide(Robot& robot, Robot& robot2)
{
    robot.setDead();
    robot2.setDead();
    return true;
}
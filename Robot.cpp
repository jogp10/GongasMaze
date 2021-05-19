//T02_G11

#include "Robot.h"
#include <iostream>

using namespace std;


Robot::Robot(const Position& position)
{
    id = robotCounter;
    this->row = position.row;
    this->col = position.col;
}

void Robot::setMove(const Movement& movement)
{
    row += movement.dRow;
    col += movement.dCol;
}

void Robot::setDead()
{
    live = false;
}

unsigned int Robot::getId() const
{
    return id;
}

unsigned int Robot::getRow() const
{
    return row;
}

unsigned int Robot::getCol() const
{
    return col;
}

char Robot::getSymbol() const
{
    if(live == true) return 'R';
    else return 'r';
}

bool Robot::getLive() const
{
    return live;
}

void Robot::show() const 
{
    cout << "Y: " << row << "/" << "X: " << col << '/' << "Status: " << live << endl;
    cout << id << endl;
}
//T02_G11

#include "Robot.h"
#include <iostream>

using namespace std;

unsigned int Robot::robotCounter = 0;

/** Robot -> get info from robot's location
* @param row
* @param col
 */
Robot::Robot(unsigned int row, unsigned int col)
{
    robotCounter++; 
    id = robotCounter;
    this->row = row;
    this->col = col;
}

/**
 * setMove -> move robot
 * @param movement
 */
void Robot::setMove(const Movement& movement)
{
    this->row += movement.dRow;
    this->col += movement.dCol;
}

/**
 * setDead -> robot is now dead
 */
void Robot::setDead()
{
    live = false;
}

/**
 * getID -> get robot's id
 * @param symbol
 */
unsigned int Robot::getId() const
{
    return id;
}

/**
 * getRow -> get robot's row
 * @return
 */
unsigned int Robot::getRow() const
{
    return row;
}

/**
 * getCol -> get robot's col
 * @return
 */
unsigned int Robot::getCol() const
{
    return col;
}

/**
 * getSymbol -> get robot's symbol
 * @return
 */
char Robot::getSymbol() const
{
    if(live) return 'R';
    else return 'r';
}

/**
 * getLive -> get robot's live
 * @return
 */
bool Robot::getLive() const
{
    return live;
}

/**
 * show -> show info's
 */
void Robot::show() const 
{
    cout << "Y: " << row << "/" << "X: " << col << '/' << "Status: " << live << endl;
    cout << "id: " << id << endl;
}
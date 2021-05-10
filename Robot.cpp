//T02_G11

#include "game.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;


Robot::Robot(unsigned int id)
{
    this->id = id;
}

Robot::Robot(unsigned int id, unsigned int y_position, unsigned int x_position, bool live)
{
    this->id = id;
    this->y_position = y_position;
    this->x_position = x_position;
    this->live = live;
}

void Robot::setY_position(unsigned int y_position)
{
    this->y_position = y_position;
}

void Robot::setX_position(unsigned int x_position)
{
    this->x_position = x_position;
}

void Robot::setY_move(int y)
{
    this->y = y;
    y_position += y;
}

void Robot::setX_move(int x)
{
    this->x = x;
    x_position += x;
}

void Robot::setLive(bool live)
{
    this->live = live;
}


unsigned int Robot::getId() const
{
    return id;
}

unsigned int Robot::getYposition() const
{
    return y_position;
}

unsigned int Robot::getXposition() const
{
    return x_position;
}

int Robot::getYmove() const
{
    return y;
}

int Robot::getXmove() const
{
    return x;
}

bool Robot::getLive() const
{
    return live;
}

void Robot::show() const 
{
    cout << "Y: " << y_position << "/" << "X: " << x_position << '/' << "Status: " << live << endl;
    cout << "Last move(y/x): " << y << "/" << x << endl << id << endl;
}
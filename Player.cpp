//T02_G11

#include "Player.h"
#include <iostream>


using namespace std;


Player::Player()
{
}

Player::Player(unsigned int y_position, unsigned int x_position, bool live)
{
    this->y_position = y_position;
    this->x_position = x_position;
    this->live = live;
}

void Player::setY_position(unsigned int y_position)
{
    this->y_position = y_position;
}

void Player::setX_position(unsigned int x_position)
{
    this->x_position = x_position;
}

void Player::setY_move(int y)
{
    this->y = y;
    y_position += y;
}

void Player::setX_move(int x)
{
    this->x = x;
    x_position += x;
}

void Player::setLive(bool live)
{
    this->live = live;
}


unsigned int Player::getYposition() const
{
    return y_position;
}

unsigned int Player::getXposition() const
{
    return x_position;
}

int Player::getYmove() const
{
    return y;
}

int Player::getXmove() const
{
    return x;
}

bool Player::getLive() const
{
    return live;
}

void Player::show() const 
{
    cout << "Y: " << y_position << "/" << "X: " << x_position << '/' << "Status: " << live << endl;
    cout << "Last move(y/x): " << y << "/" << x << endl;
}

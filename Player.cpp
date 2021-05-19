//T02_G11

#include "Player.h"
#include <iostream>


using namespace std;


Player::Player(const Position& position, char symbol)
{
    this->row = position.row;
    this->col = position.col;
    this->symbol = symbol;
    if(symbol == 'H') live = true;
    else live = false;
}


void Player::setMove(const Movement& movement)
{
    row += movement.dRow;
    col += movement.dCol;
}

void Player::setDead()
{
    symbol = 'h';
    live = false;
}


unsigned int Player::getRow() const
{
    return row;
}

unsigned int Player::getCol() const
{
    return col;
}

char Player::getSymbol() const
{
    return symbol;
}

bool Player::getLive() const
{
    return live;
}

void Player::show() const 
{
    cout << "Y: " << row << "/" << "X: " << col << '/' << "Status: " << live << "Symbol: " << symbol << endl;
}

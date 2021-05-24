//T02_G11

#include "Player.h"
#include <iostream>


using namespace std;


Player::Player(unsigned int row, unsigned int col, char symbol)
{
    this->row = row;
    this->col = col;
    this->symbol = symbol;
    if(symbol == 'h') live = false;
}

Player::Player(){}

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

void Player::setRow(unsigned int row)
{
    this->row = row; 
}

void Player::setCol(unsigned int col)
{
    this->col = col; 
}

void Player::setSymbol(char symbol)
{
    this->symbol = symbol; 
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

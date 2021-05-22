//T02_G11

#include "Player.h"
#include <iostream>


using namespace std;


Player::Player(unsigned int row, unsigned int col, char symbol)
{
    this->row = row;
    this->col = col;
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

void setRow(unsigned int row)
{
    this->row = row; 
}

void setCol(unsigned int col)
{
    this->col = col; 
}

void setSymbol(char symbol)
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

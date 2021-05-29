//T02_G11

#include "Player.h"

/**
 * setMove -> move player
 * @param movement
 */
void Player::setMove(const Movement& movement)
{
    row += movement.dRow;
    col += movement.dCol;
}

/**
 * setDead -> player is now dead
 */
void Player::setDead()
{
    symbol = 'h';
    live = false;
}

/**
 * setRow -> locate player's row
 * @param row
 */
void Player::setRow(unsigned int row)
{
    this->row = row;
}

/**
 * setCol -> locate player's col
 * @param col
 */
void Player::setCol(unsigned int col)
{
    this->col = col; 
}

/**
 * setSymbol -> set player's symbol
 * @param symbol
 */
void Player::setSymbol(char symbol)
{
    this->symbol = symbol; 
}

/**
 * getRow -> get player's row
 * @return
 */
unsigned int Player::getRow() const
{
    return row;
}

/**
 * getCol -> get player's col
 * @return
 */
unsigned int Player::getCol() const
{
    return col;
}

/**
 * getSymbol -> get player's symbol
 * @return
 */
char Player::getSymbol() const
{
    return symbol;
}

/**
 * getLive -> get player's live
 * @return
 */
bool Player::getLive() const
{
    return live;
}

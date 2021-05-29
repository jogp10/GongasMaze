//T02_G11

#include "Post.h"


/**
 * Post -> get info from post's location
 * @param row
 * @param col
 * @param type
 */
Post::Post(unsigned int row, unsigned int col, char type){
    this->row = row; 
    this->col = col;
    this->type = type;
    if(type == '*') electric =  true;
}

/**
 * setSymbol -> electric or not
 * @param type
 */
void Post::setSymbol(char type)
{
    this->type = type;
    if(type == '*') electric = true;
}

/**
 * getRow -> get post's row
 * @return
 */
unsigned int Post::getRow() const 
{
    return row; 
}

/**
 * getCol -> get post's col
 * @return
 */
unsigned int Post::getCol() const
{
    return col; 
}

/**
 * getSymbol -> get post's symbol
 * @return
 */
char Post::getSymbol() const
{
    return type;
}

/**
 * getLive -> get post's state
 * @return
 */
bool Post::getElectric() const
{
    return electric; 
}
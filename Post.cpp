//T02_G11

#include "Post.h"
#include <iostream>

using namespace std; 

Post::Post(unsigned int row, unsigned int col, char type){
    this->row = row; 
    this->col = col;
    if(type == '*') electric =  true;
}

unsigned int Post::getRow() const 
{
    return row; 
}

unsigned int Post::getCol() const
{
    return col; 
}

char Post::getSymbol() const
{
    return type;
}

bool Post::getEletric() const
{
    return electric; 
}

void Post::show()
{
    cout << "col: " << col << endl; 
    cout << "row: " << row << endl; 
    cout << "type: " << type << endl;
    cout << "electric: " << electric << endl; 
}

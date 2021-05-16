//T02_G11

#include "Post.h"
#include <iostream>

using namespace std; 

Post::Post()
{
}

Post::Post(unsigned int posY, unsigned int posX, bool eletric=false){
    this->posX = posX; 
    this->posY = posY; 
    this->eletric = eletric; 
}

void Post::setX(unsigned int posX)
{
    this->posX = posX; 
}

void Post::setY(unsigned int posY)
{
    this->posY = posY; 
}

void Post::setEletric(bool eletric)
{
    this->eletric = eletric; 
}

unsigned int Post::getX() const
{
    return posX; 
}

unsigned int Post::getY() const 
{
    return posY; 
}

bool Post::getEletric() const
{
    return eletric; 
}

void Post::show()
{
    cout << "posX: " << posX << endl; 
    cout << "posY: " << posY << endl; 
    cout << "electric: " << eletric; 
}

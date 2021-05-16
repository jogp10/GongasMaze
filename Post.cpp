//T02_G11

#include "Post.h"
#include <iostream>

using namespace std; 

Post::Post()
{
}

Post::Post(unsigned int posY, unsigned int posX, bool eletric){
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

/*
// Testing if everything is working fine
int main()
{
    unsigned int posX, posY; bool eletric;
    posX = 45; posY = 55; eletric = true; 

    Post a(posY, posX, eletric); 

    a.show(); 
    a.setX(55); 
    a.setY(99); 
    a.setEletric(false); 
    cout << endl; 
    a.getX(); 
    a.getY(); 
    a.getEletric(); 

    a.show(); 

    return 0; 
}
*/



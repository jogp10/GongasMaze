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


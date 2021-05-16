//T02_G11
#ifndef T02_G11_POST_H
#define T02_G11_POST_H

#include <iostream>

using namespace std;

class Post
{   
public: 
    Post(); 
    Post(unsigned int posY, unsigned int posX, bool eletric); 

    void setX(unsigned int posX); 
    void setY(unsigned int posY); 
    void setEletric(bool eletric); 
    
    unsigned int getX() const; 
    unsigned int getY() const; 
    bool getEletric() const; 

    void show(); 

private: 
    unsigned int posX = 0; 
    unsigned int posY = 0;  
    bool eletric = false; 
};


#endif //T02_G11_POST_H
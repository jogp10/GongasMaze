//T02_G11
#ifndef T02_G11_POST_H
#define T02_G11_POST_H

#include <iostream>

using namespace std;

class Post
{   
public: 
    Post(unsigned int row, unsigned int col, char type = '+'); 

    void setSymbol(char type);

    unsigned int getRow() const; 
    unsigned int getCol() const;
    char getSymbol() const;
    bool getEletric() const; 

    void show();

private: 
    unsigned int row, col; 
    char type;
    bool electric=false; 
};


#endif //T02_G11_POST_H
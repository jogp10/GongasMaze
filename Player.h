//T02_G11
#ifndef T02_G11_PLAYER_H
#define T02_G11_PLAYER_H

#include "structs.h"
#include <iostream>

using namespace std;

class Player
{
public:
    Player(unsigned int row, unsigned int col, char symbol);
    Player();
    
    void setMove(const Movement& movement);
    void setDead();
    void setRow(unsigned int row); 
    void setCol(unsigned int col); 
    void setSymbol(char symbol); 

    unsigned int getRow() const;
    unsigned int getCol() const;
    char getSymbol() const;
    bool getLive() const;

    void show() const;
    ~Player() {}
private:
    unsigned int row, col;
    bool live = true;
    char symbol = 'H';
};

#endif //T02_G11_PLAYER_H
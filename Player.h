//T02_G11
#ifndef T02_G11_PLAYER_H
#define T02_G11_PLAYER_H

#include "structs.h"
#include <iostream>

using namespace std;

class Player
{
public:
    Player(const Position& position, char symbol);
    
    void setMove(const Movement& movement);
    void setDead();

    unsigned int getRow() const;
    unsigned int getCol() const;
    char getSymbol() const;
    bool getLive() const;

    void show() const;
private:
    unsigned int row, col;
    bool live;
    char symbol;
};

#endif //T02_G11_PLAYER_H
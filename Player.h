//T02_G11
#ifndef T02_G11_PLAYER_H
#define T02_G11_PLAYER_H

#include "structs.h"

class Player
{
public:
    //constructors
    Player() = default;

    //methods
    void setMove(const Movement& movement);
    void setDead();
    void setRow(unsigned int row); 
    void setCol(unsigned int col); 
    void setSymbol(char symbol); 

    //get functions
    unsigned int getRow() const;
    unsigned int getCol() const;
    char getSymbol() const;
    bool getLive() const;

    //destructor
    ~Player() = default;
private:
    unsigned int row=0, col=0;
    bool live = true;
    char symbol = 'H';
};

#endif //T02_G11_PLAYER_H
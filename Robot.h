//T02_G11
#ifndef T02_G11_ROBOT_H
#define T02_G11_ROBOT_H

#include "structs.h"
#include <iostream>

using namespace std;

class Robot
{
public:
    enum State{ ALIVE, STUCK, DEAD};
    Robot(unsigned int row, unsigned int col);
    
    void setMove(const Movement& movement);
    void setDead();

    unsigned int getId() const;
    unsigned int getRow() const;
    unsigned int getCol() const;
    char getSymbol() const;
    bool getLive() const;

    void show() const;
private:
    static unsigned int robotCounter;
    unsigned int id;
    unsigned int row, col;
    bool live=true;
};

#endif //T02_G11_ROBOT_H
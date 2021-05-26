//T02_G11
#ifndef T02_G11_ROBOT_H
#define T02_G11_ROBOT_H

#include "structs.h"
#include <iostream>

using namespace std;

class Robot
{
public:
    //constructor
    Robot(unsigned int row, unsigned int col);

    // methods
    void setMove(const Movement& movement);
    void setDead();

    // get functions
    unsigned int getId() const;
    unsigned int getRow() const;
    unsigned int getCol() const;
    char getSymbol() const;
    bool getLive() const;

    // cout
    void show() const;
private:
    static unsigned int robotCounter; // count number of robots
    unsigned int id;
    unsigned int row, col;
    bool live=true;
};

#endif //T02_G11_ROBOT_H
//T02_G11
#ifndef T02_G11_ROBOT_H
#define T02_G11_ROBOT_H

#include <iostream>

using namespace std;

class Robot
{
public:
    Robot(unsigned int id);
    Robot(unsigned int id, unsigned int y_position, unsigned int x_position, bool live=true);
    
    void setY_position(unsigned int y_position);
    void setX_position(unsigned int x_position);
    void setY_move(int y=0);
    void setX_move(int x=0);
    void setLive(bool live);

    unsigned int getId() const;
    unsigned int getYposition() const;
    unsigned int getXposition() const;
    int getYmove() const;
    int getXmove() const;
    bool getLive() const;

    void show() const;
private:
    unsigned int id;
    unsigned int y_position=0;
    unsigned int x_position=0;
    int y=0;
    int x=0;
    bool live=true;
};

#endif //T02_G11_ROBOT_H
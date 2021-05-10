//T02_G11

#include "game.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

class Player
{
public:
    Player();
    Player(unsigned int y_position, unsigned int x_position, bool live=true);
    
    void setY_position(unsigned int y_position);
    void setX_position(unsigned int x_position);
    void setY_move(int y=0);
    void setX_move(int x=0);
    void setLive(bool live);

    unsigned int getYposition() const;
    unsigned int getXposition() const;
    int getYmove() const;
    int getXmove() const;
    bool getLive() const;

    void show() const;
private:
    unsigned int y_position;
    unsigned int x_position;
    int y=0;
    int x=0;
    bool live;
};

Player::Player()
{
    
}

Player::Player(unsigned int y_position, unsigned int x_position, bool live)
{
    this->y_position = y_position;
    this->x_position = x_position;
    this->live = live;
}

void Player::setY_position(unsigned int y_position)
{
    this->y_position = y_position;
}

void Player::setX_position(unsigned int x_position)
{
    this->x_position = x_position;
}

void Player::setY_move(int y)
{
    this->y = y;
    y_position += y;
}

void Player::setX_move(int x)
{
    this->x = x;
    x_position += x;
}

void Player::setLive(bool live)
{
    this->live = live;
}

unsigned int Player::getYposition() const
{
    return y_position;
}

unsigned int Player::getXposition() const
{
    return x_position;
}

int Player::getYmove() const
{
    return y;
}

int Player::getXmove() const
{
    return x;
}

bool Player::getLive() const
{
    return live;
}

void Player::show() const 
{
    cout << "Y: " << y_position << "/" << "X: " << x_position << '/' << "Status: " << live << endl;
    cout << "Last move(y/x): " << y << "/" << x << endl;
}


int main(){
    vector<Player> Players;

    Player id(3, 4);
    id.show();
    id.setX_move(-1);
    id.setY_move();

    assert(id.getLive() == true);

    id.setLive(false);

    assert(id.getXmove() == -1);
    assert(id.getYmove() == 0);
    assert(id.getLive() == false);
    assert(id.getYposition() == 3);
    assert(id.getXposition() == 3);

    id.show();

    return 0;
}

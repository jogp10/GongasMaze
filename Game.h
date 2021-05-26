//T02_G11
#ifndef T02_G11_GAME_H
#define T02_G11_GAME_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "Maze.h"
#include "Robot.h"

using namespace std;

class Game
{
public:
    Game(const string & filename); //import maze and store in vector positions of Robots 
                                   // and Player
    bool play(); 
    ~Game() {}

private: 
    void showGameDisplay() const; 
    bool isValid(Movement& movement);
    bool checkcollide(Robot& robot, Movement& movement);
    bool collide(Robot& robot, Post& post, Movement& movement); 
    bool collide(Robot& robot, Player& player); 
    bool collide(Robot& robot, Robot& robot2);

private: 
    Maze maze; 
    Player player; 
    vector<Robot> robots; 
};


#endif //T02_G11_GAME_H
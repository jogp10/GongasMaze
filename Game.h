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
    bool play(); // where the gameplay itself takes place 
    int robots_turn(int count); // where all the moves happen 
    ~Game() {} //deconstructor

private: 
    void showGameDisplay() const; // display Maze
    bool isValid(Movement& movement); // check if movement is valid 
    bool checkcollide(Robot& robot, Movement& movement); //check if there is a collision
    bool collide(Robot& robot, Post& post, Movement& movement); // collision between robot and post (movement if eletric == true)  
    bool collide(Robot& robot, Player& player); // collision between robot and player 
    bool collide(Robot& robot, Robot& robot2); // collision between 2 robots 

private: 
    Maze maze; 
    Player player; 
    vector<Robot> robots; 
};


#endif //T02_G11_GAME_H
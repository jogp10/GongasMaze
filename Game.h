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
    explicit Game(const string & filename); //import maze and store in vector positions of Robots
                                   // and Player
    bool play(); // where the gameplay itself takes place 
    void robots_turn(); // where all the moves happen 
    ~Game() = default; //deConstructor

private: 
    void showGameDisplay() const; // display Maze
    bool isValid(Movement& movement); // check if movement is valid 
    bool checkCollide(Robot& robot, Movement& movement); //check if there is a collision
    template<typename T>
    static bool collide(T& object, Post& post, Movement& movement); // collision between robot and post (movement if electric == true)
    static bool collide(Robot& robot, Player& player); // collision between robot and player
    static bool collide(Robot& robot, Robot& robot2); // collision between 2 robots

private: 
    Maze maze; 
    Player player; 
    vector<Robot> robots; 
};


#endif //T02_G11_GAME_H
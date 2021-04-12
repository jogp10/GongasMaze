//T02_G11
#ifndef T02_G11_GAME_H
#define T02_G11_GAME_H

#include "game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


/**
 *
 * @param level of the maze
 * @return the path of level
 */
bool check_path(int level, string &path);

/**
Main menu
 */
int menu();

/**
Rules of the game
 */
void ReadRules();

/**
Transform level maze to a vector
@param n number of level
Function to print the vector
@param vector that's going to be printed
*/
vector<string> ReadMaze(string path);
void print(vector<string> vec);

/**
Function to display all the mazes when selecting level
@param n number of level
 */
void DisplayMaze(int n, string path);

/**
 * Valid Move
 * @param vec maze level
 * @param y player's position
 * @param x player's position
 * @param vertical y player's move
 * @param horizontal x player's move
 * @return if invalid play, ask for another
 */
bool validmove(vector<string> &vec, int &y, int &x, int vertical = 0, int horizontal = 0);

/**
 * Move player
 * @param vec maze level
 * @param y player's position
 * @param x player's position
 * @param vertical y player's move
 * @param horizontal x player's move
 * @return player status ( true for alive, false otherwise)
 */
bool movePlayer(vector<string> &vec, int &y, int &x, int vertical = 0, int horizontal = 0);

/**
 * Player's move
 * @param vec maze
 * @param y player's position
 * @param x player's position
 * @return player status
 */
bool player(vector<string> &vec, int &y, int &x, char play);

/**
 * Move Robot
 * @param vec maze level
 * @param yr robot's position
 * @param xr robot's position
 * @param vertical robot's move
 * @param horizontal robot's move
 * @return robot status ( robot alive -> true in case not false)
 */
bool moveRobot(vector<string> &vec, int &yr, int &xr, int vertical = 0, int horizontal = 0);

/**
Calculate which move is better for robot
@param vec refers to map after player moves
@param yp - y position of player in vec
@param xp - x position of player in vec
@param yr - y position of robot in vec
@param xr - x position of robot in vec
*/
bool robots(vector<string> &vec, int &yp, int &xp, int &yr, int &xr);

/**
Write winner's name and time in record
@param name of the player
@param time of the play
@param maze in which level
*
Boolean function to order time records
*/
void winner(char name[15],int time,int maze);
bool order(string a, string b);

/**
Start of the game
Let's play
 */
void play();

#endif //T02_G11_GAME_H
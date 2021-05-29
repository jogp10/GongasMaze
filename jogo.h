//T02_G11
#ifndef T02_G11_JOGO_H
#define T02_G11_JOGO_H

#include "Game.h"
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
Main menu
 */
int menu();

/**
Rules of the game
 */
void ReadRules();

/**
 *
 * @param level of the maze
 * @return the path of level
 */
bool check_path(int level, string &path);

/**
Function to display all the mazes when selecting level
@param n number of level
 */
void DisplayFile(const string& path, int n = 0);

/**
Start of the game
Let's play
 */
void play();

/**
Write winner's name and time in record
@param name of the player
@param time of the play
@param maze in which level
*
Boolean function to order time records
*/
void winner(char name[15],int time,int maze);
bool order(const string& a, const string& b);

/**
 * Display leaderboard
 */
void leaderboard();

#endif //T02_G11_JOGO_H

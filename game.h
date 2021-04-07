//T02_G11
#ifndef T02_G11_GAME_H
#define T02_G11_GAME_H
#include <iostream>
#include <vector>

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
Transform level maze to a vector
@param n number of level
Function to print the vector
@param vector that's going to be printed
*/
vector<string> ReadMaze(int n);
void print(vector<string> vec);

/**
Function to display all the mazes when selecting level
@param n number of level
 */
void DisplayMaze(int n);

/**
Start of the game
Let's play
 */
void play();
bool player(vector <string> &vec);

/**
Write winner's name and time in record
@param name of the player
@param time of the play
@param maze in which level
*
Boolean function to order time records
*/
void winner(string name, int time, int maze);
bool order(string a, string b);

#endif //T02_G11_GAME_H

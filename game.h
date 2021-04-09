//T02_G11
#ifndef T02_G11_GAME_H
#define T02_G11_GAME_H

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
bool check_path(int level, string &path){
    //replacing 'XX' with the number of maze
    path[10]= (char)(level/10 + '0');
    path[11]= (char)(level%10 + '0');
    ifstream f(path);
    if(f.good()) return true;
    return false;
}


/**
Main menu
 */
int menu(){
    int menu_choice;
    // Main Menu
    cout << "1) Rules" << endl;
    cout << "2) Play" << endl;
    cout << "3) Leaderboard" << endl; 
    cout << "0) Exit" << endl;
    cout << "Option: " ; cin >> menu_choice;

    // If the menu_choice is not valid, ask for a valid one
    while(cin.fail() || (menu_choice!=0 && menu_choice !=1 && menu_choice != 2))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cerr << "Input a valid operation! (0, 1 or 2 to proceed)" << endl;
        for(int i=0; i<=20000000; i++);  // loop to make time, so cerr always prints first than cout
        cout << "Option: "; cin >> menu_choice;
    }
    return menu_choice;
}


/**
Rules of the game
 */
void ReadRules(){
    string line;
    ifstream myfile ("rules.TXT");  // file where are the rules
    int goBack;

    // Open file and print all the lines
    if(myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    //Go back to main menu by pressing '0'
    cout << "Press '0' to go to the main menu" << endl;
    cin >> goBack;

    while(goBack != 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> goBack;
    }
}


/**
Transform level maze to a vector
@param n number of level
Function to print the vector
@param vector that's going to be printed
*/
void print(vector <string> vec){
    //Displaying maze to user using elements stored in vec
    for (auto & i : vec) cout << i << endl;
}


vector<string> ReadMaze(int n, string path){
    string line; //variable where we store individual lines
    vector <string> vec; //place where we will be storing all the lines

    ifstream file(path); //open file for read

    //insert maze in a vector
    getline(file, line);
    while (getline(file, line)) vec.push_back(line);
    print(vec); //call function print
    return vec;
}


/**
Function to display all the mazes when selecting level
@param n number of level
 */
void DisplayMaze(int n){
    string path = "Maze/MAZE_xx.TXT";
    //replacing 'xx' with the number of maze
    path[10]= (char)(n/10 + '0');
    path[11]= (char)(n%10 + '0');
    string line; //variable where we store individual lines

    ifstream file(path) ;

    // display the maze on interface
    getline(file, line);
    cout << setw(9) << "(" << n << ")" << endl;
    while (getline(file, line)) cout << line << endl;
}


/**
 * Player's move
 * @param vec maze
 * @param y player's position
 * @param x player's position
 * @return player status
 */
bool player(vector<string> &vec, int &y, int &x){
    char play;
    string check = "QWEASDZXC";

Start_play:
    //Ask the user which move he wants to do
    cout << "What's your play" << endl; cin >> play;

    while (check.find(toupper(play)) == string::npos) {
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> play;
    }

    // Move, if collision he dies. Game over
    switch (toupper(play))
    {
        case 'S': // stay place
            return true;
        case 'W': // move up
            swap(vec[y - 1][x], vec[y][x]);
            if(vec[y][x] == 'r') {
                swap(vec[y - 1][x], vec[y][x]);
                cout << "Not the play you wanted to do, try another!" << endl;
                goto Start_play;
            }
            if (vec[y][x] == '*' || vec[y][x] == 'R') {
                vec[y][x] = ' ';
                y--;
                return false;
            }
            y--;
            break;
        case 'E': // move diagonal right up
            swap(vec[y - 1][x + 1], vec[y][x]);
            if(vec[y][x] == 'r') {
                swap(vec[y - 1][x + 1], vec[y][x]);
                cout << "Not the play you wanted to do, try another!";
                goto Start_play;
            }
            if (vec[y][x] == '*' || vec[y][x] == 'R') {
                vec[y][x] = ' ';
                y--; x++;
                return false;
            }
            y--; x++;
            break;
        case 'D': // move right
            swap(vec[y][x + 1], vec[y][x]);
            if(vec[y][x] == 'r') {
                swap(vec[y][x + 1], vec[y][x]);

                cout << "Not the play you wanted to do, try another!";
                goto Start_play;
            }
            if (vec[y][x] == '*' || vec[y][x] == 'R') {
                vec[y][x] = ' ';
                x++;
                return false;
            }
            x++;
            break;
        case 'C': // move diagonal right down
            swap(vec[y + 1][x + 1], vec[y][x]);
            if(vec[y][x] == 'r') {
                swap(vec[y + 1][x + 1], vec[y][x]);
                cout << "Not the play you wanted to do, try another!";
                goto Start_play;
            }
            if (vec[y][x] == '*' || vec[y][x] == 'R') {
                vec[y][x] = ' ';
                y++; x++;
                return false;
            }
            y++; x++;
            break;
        case 'X': // move down
            swap(vec[y + 1][x], vec[y][x]);
            if(vec[y][x] == 'r') {
                swap(vec[y + 1][x], vec[y][x]);
                cout << "Not the play you wanted to do, try another!";
                goto Start_play;
            }
            if (vec[y][x] == '*' || vec[y][x] == 'R') {
                vec[y][x] = ' ';
                y++;
                return false;
            }
            y++;
            break;
        case 'Z': // move diagonal left down
            swap(vec[y + 1][x - 1], vec[y][x]);
            if(vec[y][x] == 'r') {
                swap(vec[y + 1][x - 1], vec[y][x]);
                cout << "Not the play you wanted to do, try another!";
                goto Start_play;
            }
            if (vec[y][x] == '*' || vec[y][x] == 'R') {
                vec[y][x] = ' ';
                y++; x--;
                return false;
            }
            y++; x--;
            break;
        case 'A': // move left
            swap(vec[y][x - 1], vec[y][x]);
            if(vec[y][x] == 'r') {
                swap(vec[y][x - 1], vec[y][x]);
                cout << "Not the play you wanted to do, try another!";
                goto Start_play;
            }
            if (vec[y][x] == '*' || vec[y][x] == 'R') {
                vec[y][x] = ' ';
                x--;
                return false;
            }
            x--;
            break;
        case 'Q': // move diagonal left up
            swap(vec[y - 1][x - 1], vec[y][x]);
            if(vec[y][x] == 'r') {
                swap(vec[y - 1][x - 1], vec[y][x]);
                cout << "Not the play you wanted to do, try another!";
                goto Start_play;
            }
            if (vec[y][x] == '*' || vec[y][x] == 'R') {
                vec[y][x] = ' ';
                y--; x--;
                return false;
            }
            y--; x--;
            break;
    }
    cin.ignore(10000, '\n');
    return true;
}


/**
Everything about robot moves
@param vec refers to map after player moves
@param yp - y position of player in vec
@param xp - x position of player in vec
@param yr - y position of robot in vec
@param xr - x position of robot in vec
*/ 
bool robots(vector<string> &vec, int &yp, int &xp, int &yr, int &xr)  
{
    int count = 0, indice;
    double q,w,e,a,d,z,x,c, minor = 999999; 
    vector<double> hold;  

    //case 0
    q = sqrt((pow(xp-(xr-1), 2) + pow(yp - (yr-1), 2))); hold.push_back(q); 
    //case 1
    w = sqrt((pow(xp-xr, 2) + pow(yp - (yr-1), 2))); hold.push_back(w);
    //case 2
    e = sqrt((pow(xp-(xr+1), 2) + pow(yp - (yr-1), 2))); hold.push_back(e);
    //case 3
    a = sqrt((pow(xp-(xr-1), 2) + pow(yp - yr, 2))); hold.push_back(a);
    //case 4
    d = sqrt((pow(xp-(xr+1), 2) + pow(yp - yr, 2))); hold.push_back(d);
    //case 5
    z = sqrt((pow(xp-(xr-1), 2) + pow(yp - (yr+1), 2))); hold.push_back(z);
    //case 6
    x = sqrt((pow(xp-xr, 2) + pow(yp - (yr+1), 2))); hold.push_back(x);
    //case 7
    c = sqrt((pow(xp-(xr+1), 2) + pow(yp - (yr+1), 2))); hold.push_back(c);
    
    while(count <= 7)
    {
        if (hold[count] <= minor) 
        {
            minor = hold[count];
            indice = count;
        }
        count++; 
    }

    switch(indice)
    {
        case 0: 
            swap(vec[yr-1][xr-1], vec[yr][xr]); 
            if (vec[yr][xr] == '*' || vec[yr][xr] == 'r' || vec[yr][xr] == 'R')
            {
                vec[yr][xr] = ' '; 
                vec[yr-1][xr-1] = 'r'; 
                return false; 
            }
            yr--; xr--; 
            break; 
        case 1:
            swap(vec[yr-1][xr], vec[yr][xr]);
            if (vec[yr][xr] == '*' || vec[yr][xr] == 'r' || vec[yr][xr] == 'R')
            {
                vec[yr][xr] = ' '; 
                vec[yr-1][xr] = 'r'; 
                return false; 
            }
            yr--; 
            break; 
        case 2:
            swap(vec[yr-1][xr+1], vec[yr][xr]);
            if (vec[yr][xr] == '*' || vec[yr][xr] == 'r' || vec[yr][xr] == 'R')
            {
                vec[yr][xr] = ' '; 
                vec[yr-1][xr+1] = 'r'; 
                return false; 
            }
            yr--; xr++; 
            break; 
        case 3: 
            swap(vec[yr][xr-1], vec[yr][xr]);
            if (vec[yr][xr] == '*' || vec[yr][xr] == 'r' || vec[yr][xr] == 'R')
            {
                vec[yr][xr] = ' '; 
                vec[yr][xr-1] = 'r'; 
                return false; 
            }
            xr--; 
            break; 
        case 4: 
            swap(vec[yr][xr+1], vec[yr][xr]);
            if (vec[yr][xr] == '*' || vec[yr][xr] == 'r' || vec[yr][xr] == 'R')
            {
                vec[yr][xr] = ' '; 
                vec[yr][xr+1] = 'r'; 
                return false; 
            }
            xr++; 
            break; 
        case 5:
            swap(vec[yr+1][xr-1], vec[yr][xr]);
            if (vec[yr][xr] == '*' || vec[yr][xr] == 'r' || vec[yr][xr] == 'R')
            {
                vec[yr][xr] = ' '; 
                vec[yr+1][xr-1] = 'r'; 
                return false; 
            }
            yr++; xr--; 
            break; 
        case 6: 
            swap(vec[yr+1][xr], vec[yr][xr]);
            if (vec[yr][xr] == '*' || vec[yr][xr] == 'r' || vec[yr][xr] == 'R')
            {
                vec[yr][xr] = ' '; 
                vec[yr+1][xr] = 'r'; 
                return false; 
            }
            yr++; 
            break; 
        case 7:
            swap(vec[yr + 1][xr + 1], vec[yr][xr]);
            if (vec[yr][xr] == '*' || vec[yr][xr] == 'r' || vec[yr][xr] == 'R')
            {
                vec[yr][xr] = ' '; 
                vec[yr+1][xr+1] = 'r'; 
                return false; 
            }
            yr++; xr++; 
            break; 
    }
    return true; 
}


/**
Write winner's name and time in record
@param name of the player
@param time of the play
@param maze in which level
*
Boolean function to order time records
*/
bool order(string a, string b) {return (stoi (a.substr(16, 8), nullptr) < stoi (b.substr(16, 8), nullptr));}

void winner(char name[15],int time,int maze) {
    string path = "Maze/MAZE_XX_WINNERS.TXT";   // path of file to write winners

    //Which maze, change path
    path[10] = (char) (maze / 10 + '0');
    path[11] = (char) (maze % 10 + '0');

    // open file to write win
    fstream win(path);

    if (win.is_open())
    {
        win.seekp(0, ios::end);  // starting point at the end of file
        win << left << setw(15) << name;  // size of name component
        win << internal << setw(8) << time << '\n';
        win.close();
    }

    // read all lines in a vector
    ifstream readf(path);
    vector<string> file;
    string line;

    if (readf.is_open())
    {
        while (getline(readf, line))
        {
            file.push_back(line);
        }
        readf.close();
    }

    //sort the vector
    if (file.size() > 5)
    {
        sort(file.begin() + 4, file.end(), order);
    }

    // write back into the file
    ofstream writef(path);  // open file to read and write

    if (writef.is_open())
    {
        for (auto & i : file)
        {
            writef << i << endl;
        }
        writef.close();
    }
}


/**
Start of the game
Let's play
 */
void play() {
    int MazeSelect;
    char start;
    string path = "Maze/MAZE_xx.TXT";

    //display levels
    DisplayMaze(1);
    DisplayMaze(2);

    cout << "What Maze do you like the most?" << endl;
    cin >> MazeSelect;  // which one the player wants to try

    // if he choose an invalid one, ask for another input while invalid!
    while ((cin.fail() || !check_path(MazeSelect, path)) && MazeSelect != 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cerr << "That's not a valid Maze! try another or '0' to return to main menu" << endl;
        cin >> MazeSelect;
    }
    if(MazeSelect == 0) return;

    // Very start of the game
    cout << endl << "Good choice, let's start!" << endl << "Enter S when you are READY..." << endl;
    cin >> start;

    while (start != 'S' && start != 's') cin >> start;

    // Start timer
    chrono::steady_clock time;
    auto start_time = time.now();

    // display board, ready to start
    vector<string> vec = ReadMaze(MazeSelect, path);

    // booleans for keep playing if both still alive
    bool player_live = true;
    bool robots_live = true;
    //idrobots(vec);

    //get player's position
    int y_player = 0, x_player = 0;
    for (y_player; y_player <= vec.size(); y_player++)
    {
        x_player = 0;
        for (x_player; x_player <= vec[y_player].size(); x_player++)
        {
            if (vec[y_player][x_player] == 'H') break;
        }
        if (vec[y_player][x_player] == 'H') break;
    }

    //get all robot's positions
    int y_robot = 0, x_robot = 0;
    vector<int> robot_x, robot_y;
    for (y_robot; y_robot <= vec.size()-1; y_robot++)
    {
        x_robot = 0;
        for (x_robot; x_robot <= vec[y_robot].size(); x_robot++)
        {
            if(vec[y_robot][x_robot] == 'R')
            {
                robot_x.push_back(x_robot);
                robot_y.push_back(y_robot);
            }
        }
    }

    // move from player and automatic play from robots
    while (robots_live && player_live)
    {

        // ask the user to move
        player_live = player(vec, y_player, x_player);

        //robot's turn
        if (player_live)
        {
            vector<int> temp; // for dead robots

            for(int i=0; i<= robot_x.size()-1; i++)
            {
                //see if robot did die because anther's robot move
                if (vec[robot_y[i]][robot_x[i]] == 'r')
                {
                    temp.push_back(i);
                    continue;
                }
                //move robot
                if(!robots(vec, y_player, x_player, robot_y[i], robot_x[i]))
                {
                    temp.push_back(i);
                }

                // if robot catches player
                if(y_player == robot_y[i] && x_player == robot_x[i]) player_live = false;
            }

            //remove positions of dead robots
            int count = 0;
            for(int j : temp){
                robot_x.erase(robot_x.begin()+j-count);
                robot_y.erase(robot_y.begin()+j-count);
                count++;
            }

            if(robot_x.empty()) robots_live = false;
        }
        else vec[y_player][x_player] = 'h';
        print(vec);
    }

    auto end_time = time.now(); // finish timer

    // if player dead
    if (robots_live) {
        cout << "You lost!! Better luck next time." << endl << endl;
    }
        // if robots dead, register time
    else {
        char name[15];

        auto time_lapsed = static_cast<chrono::duration<double>>(end_time - start_time);
        cout << "What a fantastic show!! Tell me your name so i can remember it!!" << endl;
        cin.ignore();
        cin.getline(name, sizeof(name));
        winner(name, int(time_lapsed.count()), MazeSelect);
        cin.clear();
        cin.ignore(10000, '\n');
    }
}


#endif //T02_G11_GAME_H

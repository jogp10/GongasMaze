//T02_G11

#include "jogo.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


int menu(){
    int menu_choice;
    // Main Menu
    cout << "1) Rules" << endl;
    cout << "2) Play" << endl;
    cout << "3) Leaderboard" << endl;
    cout << "0) Exit" << endl;

    // Ask for menu_choice
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << "Option: "; cin >> menu_choice;
        if (cin.eof()) return 0;
        if(!cin.fail()) {
            cin.ignore(10000, '\n');
            if (menu_choice == 0) return 0;
            else if (menu_choice == 1 || menu_choice == 2 || menu_choice == 3) return menu_choice;
        }
        else{
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "Input a valid operation! (0, 1 or 2 to proceed)" << endl;
    }
}


void ReadRules(){
    string line;
    ifstream myFile ("rules.txt");  // file where are the rules
    int goBack;

    // Open file and print all the lines
    if(myFile.is_open())
    {
        while (getline(myFile, line)) cout << line << '\n';
        myFile.close();
    }

    //Go back to main menu by pressing '0'
    cout << "Press '0' to go to the main menu" << endl;

    //Test input while invalid
    while(true){
        cin >> goBack;
        if (cin.eof()) return;
        if(!cin.fail()) {
            cin.ignore(10000, '\n');
            if (goBack == 0) break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}


bool check_path(int level, string &path){
    //replacing 'XX' with the number of maze
    path[5]= (char)(level/10 + '0');
    path[6]= (char)(level%10 + '0');

    //open file and check if exists
    ifstream f(path);
    if(f.good()) return true;
    return false;
}


void DisplayFile(const string& path, int n){

    string line; //variable where we store individual lines

    ifstream file(path);

    // display the maze on interface
    getline(file, line);
    if(path.size() == 11) {
        cout << setw(9) << "(" << n << ")" << endl;
    }
    while(getline(file, line)) cout << line << endl;
}


void play() {
    int MazeSelect;
    char start;
    string path = "MAZE_xx.txt";

    //display levels
    for(int l=1; l<=99; l++)
    {
        if(check_path(l, path)) DisplayFile(path, l);
    }

    // ask for a level to play
    cout << "What Maze do you wanna play?" << endl;

    while(true)
    {
        cin >> MazeSelect;
        if (cin.eof()) return;
        if(!cin.fail()){
            cin.ignore(10000, '\n');
            if(MazeSelect == 0) return;
            else if(check_path(MazeSelect, path)) break;
        }
        else{
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "That's not a valid Maze! try another or '0' to return to main menu" << endl;
    }

    // Very start of the game
    cout << endl << "Good choice, let's start!" << endl << "Enter 'S' when you are READY..." << endl;
    while(true){
        cin >> start;
        if (cin.eof()) return;
        if(!cin.fail()) {
            cin.ignore(10000, '\n');
            if (start == 'S' || start == 's') break;
        }
        else{
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    //display level
    Game game(path);

    // Start timer
    auto start_time = chrono::steady_clock::now();
    
    // Start game
    bool match_point;
    match_point = game.play();

/**
    // move from player and automatic play from robots
    while (robots_live && player_live) {

        /**
        //move player
        player_live = player(vec, y_player, x_player, exitGame);
        if(exitGame) return;
        

        //robot's turn
        if (player_live) {
            int R_oldY, R_oldX; // to register old position of dead Robot's ( which now is (0, 0))

            for (int i = 0; i < robot_x.size(); i++) {

                //see if robot die because anther's robot move
                if (vec[robot_y[i]][robot_x[i]] == 'r') {
                    robot_y[i]=0; robot_x[i]=0;
                    continue;
                }

                //move robot
                else if (!robots(vec, y_player, x_player, robot_y[i], robot_x[i], R_oldY, R_oldX))
                {
                    for(int w=0; w<i; w++)
                    {
                        if(robot_x[w] == R_oldX && robot_y[w] == R_oldY) // if robot catches another alive robot
                        {
                            robot_x[w]=0; robot_y[w]=0;
                        }
                    }
                }

                // if robot catches player
                if (y_player == robot_y[i] && x_player == robot_x[i]) player_live = false;
            }

            //remove positions of dead robots
            int max = robot_x.size();
            int count = 0;
            for (int j=0; j<max; j++)
            {
                if(robot_x[j-count] == 0 && robot_y[j-count] == 0)
                {
                    robot_x.erase(robot_x.begin() + j - count);
                    robot_y.erase(robot_y.begin() + j - count);
                    count++;
                }
            }

            if (robot_x.empty()) robots_live = false; // if all robots died, game over
        }
        print(vec); // print level with update
        
    }
    */

    auto end_time = chrono::steady_clock::now(); // finish timer

    // if player dead
    if (!match_point) {
        cout << "You lost!! Better luck next time." << endl << endl;
    }
    // if robots dead, register time
    else {
        char name[15];

        auto time_lapsed = static_cast<chrono::duration<double>>(end_time - start_time);
        cout << "What a fantastic show!!\nYou completed the level in "; cout << int(time_lapsed.count()); cout << " seconds!!!\n";
        cout << "Tell me your name so i can remember it!!\n";
        cin.getline(name, sizeof(name));
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if(cin.eof()) return;

        winner(name, int(time_lapsed.count()), MazeSelect);
    }
}

/**
bool player(vector<string> &vec, int &y, int &x, bool& exitGame){
    while(true) {

        char play;
        string check = "QWEASDZXC"; //possible plays

        // ask for a play
        cout << "What's your play" << endl;

        while(true){
            cin >> play;
            if (cin.eof()) {
                exitGame = true;
                return true;
            }
            if(!cin.fail()) {
                cin.ignore(10000, '\n');
                if (check.find((char) toupper(play)) != string::npos) break;
            }
            else {
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        // Move, if collision -> he dies. Game over
        switch (toupper(play)) {
            case 'W': // move up
                if (!validMove(vec, y, x, -1)) break;  // test valid move
                return movePlayer(vec, y, x, -1);  // update player status ( alive or dead)

            case 'E': // move diagonal right up
                if (!validMove(vec, y, x, -1, +1)) break;
                return movePlayer(vec, y, x, -1, +1);

            case 'D': // move right
                if (!validMove(vec, y, x, 0, +1)) break;
                return movePlayer(vec, y, x, 0, +1);

            case 'C': // move diagonal right down
                if (!validMove(vec, y, x, +1, +1)) break;
                return movePlayer(vec, y, x, +1, +1);

            case 'X': // move down
                if (!validMove(vec, y, x, +1)) break;
                return movePlayer(vec, y, x, +1);

            case 'Z': // move diagonal left down
                if (!validMove(vec, y, x, +1, -1)) break;
                return movePlayer(vec, y, x, +1, -1);

            case 'A': // move left
                if (!validMove(vec, y, x, 0, -1)) break;
                return movePlayer(vec, y, x, 0, -1);

            case 'Q': // move diagonal left up
                if (!validMove(vec, y, x, -1, -1)) break;
                return movePlayer(vec, y, x, -1, -1);

            default:   // stay place
                return true;
        }
    }
}
*/

/**
bool movePlayer(vector<string> &vec, int &y, int &x, int vertical, int horizontal)
{
    swap(vec[y + vertical][x + horizontal], vec[y][x]);  // move player
    if (vec[y][x] == '*' || vec[y][x] == 'R') {  // if player moves causes death
        vec[y][x] = ' ';
        vec[y + vertical][x + horizontal] = 'h';  // update player's status
        return false;
    }
    // update player's position
    y += vertical;
    x += horizontal;
    return true;
}
*/


/**
bool validMove(vector<string> &vec, int &y, int &x, int vertical, int horizontal)
{
    if (vec[y + vertical][x + horizontal] == 'r') {   // if player move is against a stuck robot
        cout << "Not the play you wanted to do, try another! ";
        return false; // Not a valid move
    }
    return true;
}
*/

/**
bool robots(vector<string> &vec, int &yp, int &xp, int &yr, int &xr, int &yrO, int &xrO)
{
    int indice;
    double q,w,e,a,d,z,x,c, minor = 999999;
    vector<double> minor_d;

    //case 0
    q = sqrt((pow(xp-(xr-1), 2) + pow(yp - (yr-1), 2))); minor_d.push_back(q);
    //case 1
    w = sqrt((pow(xp-xr, 2) + pow(yp - (yr-1), 2))); minor_d.push_back(w);
    //case 2
    e = sqrt((pow(xp-(xr+1), 2) + pow(yp - (yr-1), 2))); minor_d.push_back(e);
    //case 3
    a = sqrt((pow(xp-(xr-1), 2) + pow(yp - yr, 2))); minor_d.push_back(a);
    //case 4
    d = sqrt((pow(xp-(xr+1), 2) + pow(yp - yr, 2))); minor_d.push_back(d);
    //case 5
    z = sqrt((pow(xp-(xr-1), 2) + pow(yp - (yr+1), 2))); minor_d.push_back(z);
    //case 6
    x = sqrt((pow(xp-xr, 2) + pow(yp - (yr+1), 2))); minor_d.push_back(x);
    //case 7
    c = sqrt((pow(xp-(xr+1), 2) + pow(yp - (yr+1), 2))); minor_d.push_back(c);

    for(int j=0; j<=7; j++)
    {
        if (minor_d[j] <= minor) // see which distance is minor
        {
            minor = minor_d[j];
            indice = j;
        }
    }

    switch(indice)
    {
        case 0:  // Q
            return moveRobot(vec, yr, xr, yrO, xrO, -1, -1);
        case 1: // W
            return moveRobot(vec, yr, xr,yrO, xrO, -1);
        case 2: // E
            return moveRobot(vec, yr, xr,yrO, xrO, -1, +1);
        case 3:  // A
            return moveRobot(vec, yr, xr,yrO, xrO, 0, -1);
        case 4: // D
            return moveRobot(vec, yr, xr,yrO, xrO, 0, +1);
        case 5: // Z
            return moveRobot(vec, yr, xr,yrO, xrO, +1, -1);
        case 6:  // X
            return moveRobot(vec, yr, xr,yrO, xrO, +1);
        case 7: // C
            return moveRobot(vec, yr, xr,yrO, xrO, +1, +1);
        default:
            return true;
    }
}
*/
/**
bool moveRobot(vector<string> &vec, int &yr, int &xr, int &yrO, int &xrO, int vertical, int horizontal)
{
    swap(vec[yr + vertical][xr + horizontal], vec[yr][xr]);  // move robot
    if (vec[yr][xr] == '*' || vec[yr][xr] == 'r' || vec[yr][xr] == 'R')  // if move causes death to the robot
    {
        yrO = yr + vertical;
        xrO = xr + horizontal;
        vec[yr][xr] = ' ';  // eliminate cause of death
        vec[yr + vertical][xr + horizontal] = 'r';  // new position of R is now a stuck robot
        yr=0; xr=0;
        return false;
    }
    else if(vec[yr][xr] == 'H') vec[yr][xr] = ' ';  // if robot catches player
    yr += vertical; xr += horizontal;
    return true;
}
*/

void winner(char name[15],int time,int maze) {
    string path = "MAZE_XX_WINNERS.txt";   // path of file to write winners

    //Which maze, change path
    path[5] = (char) (maze / 10 + '0');
    path[6] = (char) (maze % 10 + '0');

    // open file to write win
    fstream win(path);

    if (win.is_open())
    {
        win.seekp(0, ios::end);  // starting point at the end of file
        win << left << setw(15) << name;  // size of name component
        win << internal << setw(8) << time << '\n';
        win.close();
    }
    else 
    {
        ofstream make_file(path);

        make_file << "T02_G11\n\nPlayer          - Time\n-----------------------\n";
        make_file << left << setw(15) << name;  // size of name component
        make_file << internal << setw(8) << time << endl;
        make_file.close(); 
        return;
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

bool order(const string& a, const string& b) {return (stoi (a.substr(16, 8), nullptr) < stoi (b.substr(16, 8), nullptr));}

void leaderboard(){
    int level;
    int ret;
    string path = "MAZE_xx_WINNERS.txt";

    cout << "Which level do you want to beat the records?" << endl;

    while(true){
        cin >> level;
        if (cin.eof()) return;
        if(!cin.fail()) {
            cin.ignore(10000, '\n');
            if (level == 0) return;
            else if (check_path(level, path)) break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cerr << "empty list! try another or '0' to return to main menu" << endl;
    }

    //read_level
    DisplayFile(path);
    cout << "\n\n0 to go back to main menu\n";

    while(true){
        cin >> ret;
        if (cin.eof()) break;
        if(!cin.fail()) {
            cin.ignore(10000, '\n');
            if (ret == 0) break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
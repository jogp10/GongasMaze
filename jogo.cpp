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

    //Test input
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
    if(path.size() == 11) { // in case of level, otherwise is a leaderboard
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

    //test input
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

    // Finish timer
    auto end_time = chrono::steady_clock::now();

    // if player dead
    if (!match_point) {
        cout << "You lost!! Better luck next time." << endl << endl;
    }
    // if player won
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

// function to order time of plays
bool order(const string& a, const string& b) {return (stoi (a.substr(16, 8), nullptr) < stoi (b.substr(16, 8), nullptr));}


void leaderboard(){
    int level;
    int ret;
    string path = "MAZE_xx_WINNERS.txt";

    // Ask for a level to display leaderboard
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

    //read file MAZE_XX_WINNERS
    DisplayFile(path);

    //Back to main menu
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
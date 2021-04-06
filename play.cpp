//T02_G11

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "header.h"

using namespace std;


int menu(){
    int menu_choice;

    // Main Menu
    cout << "1) Rules" << endl;
    cout << "2) Play" << endl;
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


void print(vector <string> vec){
    //Displaying maze to user using elements stored in vec
    for (auto & i : vec) cout << i << endl;
}


void ReadMaze(int n){
    string path = "Maze/MAZE_xx.TXT";
    //replacing 'XX' with the number of maze
    path[10]= (char)(n/10 + '0');
    path[11]= (char)(n%10 + '0');
    string line; //variable where we store individual lines
    vector <string> vec; //place where we will be storing all the lines

    ifstream file(path); //open file for read

    //insert maze in a vector
    getline(file, line);
    while (getline(file, line)) vec.push_back(line);
    print(vec); //call function print
}

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


void play(){
    int MazeSelect;
    char start;

    //display levels
    DisplayMaze(1); 
    DisplayMaze(2);

    cout << "What Maze do you like the most?" << endl; cin >> MazeSelect;  // which one the player wants to try

    // if he choose an invalid one, ask for another input while invalid!
    while (cin.fail() || (MazeSelect != 1 && MazeSelect != 2))
    {
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cerr << "Choose a Maze between 1 and 2! " << endl; cin >> MazeSelect;
    }

    // Very start of the game
    cout << endl << "Good choice, let's start!" << endl << "Enter S when you are READY..." << endl; 
    cin >> start; 

    while (start != 'S' && start != 's') cin >> start;

    // Start timer
    chrono::steady_clock time;
    auto start_time = time.now();
    /**
     * for the end of game, time of the play
    auto end_time = time.now();
    auto time_lapsed = static_cast<chrono::duration<double>>(end_time-start_time);
    int(time_lapsed.count()); */

    // display board, ready to start
    ReadMaze(MazeSelect); 
    cout << "Done!" << endl;

    //develop here
}

bool order(string a, string b) {return (stoi (a.substr(16, 8), nullptr) < stoi (b.substr(16, 8), nullptr));}

void winner(string name,int time,int maze){
    string path= "Maze/MAZE_XX_WINNERS.TXT";   // path of file to write winners

    //Which maze, change path
    path[10] = (char)(maze/10+'0');
    path[11] = (char)(maze%10+'0');

    // open file to write win
    fstream win(path);

    if (win.is_open()) {
        win.seekp(0, ios::end);  // starting point at the end of file
        win << left << setw(15) << name;  // size of name component
        win << internal << setw(8) << time << '\n';
        win.close();
    }

    // write all lines in a vector
    ifstream readf(path);
    vector<string> file;
    string line;

    if(readf.is_open()) {
        while (getline(readf, line)) {
            file.push_back(line);
        }
        readf.close();
    }

    //sort the vector
    if(file.size()>5) {
        sort(file.begin() + 4, file.end()-1, order);
    }

    // write back into the file
    ofstream writef(path);  // open file to read and write

    if (writef.is_open()) {
        for(int i=0; i<=file.size()-1; i++){
            writef << file[i] << endl;
        }
        int j = file.size();
        writef << file[j];
        writef.close();
    }
}

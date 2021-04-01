//T02_G11

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

int menu(){
    int menu_choice;

    // Main Menu
    cout << "1) Rules" << endl;
    cout << "2) Play" << endl;
    cout << "0) Exit" << endl;
    cin >> menu_choice;

    // If the menu_choice is not valid
    while(cin.fail() || (menu_choice!=0 && menu_choice !=1 && menu_choice != 2)){
        cin.clear();
        cin.ignore(10000, '\n');
        cerr << "Input a valid operation! (0, 1 or 2 to proceed)" << endl;
        cin >> menu_choice;
    }
    return menu_choice;  // return choice
}


void ReadRules(){
    string line;
    ifstream myfile ("rules.txt");
    int goBack;

    // Open file and print all the lines
    if(myfile.is_open()) {
        while (getline(myfile, line)) {
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


void winner(string name,int time,int maze){
    string path= "Maze/MAZE_XX_WINNERS.TXT";
    path[10] = (char)(maze/10+'0');
    path[11] = (char)(maze%10+'0');
    string line;

    fstream win(path);  // open file to read and write
    win.seekp(0, ios::end);  // starting point at the end of file
    win << left << setw(15) << name;  // size of name component
    win << internal << setw(8) << time << '\n';
    win.close();
}


void play(){
    cout << "Done!" << endl;
}

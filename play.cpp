//T02_G11

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void winner(string name,int time,int maze){
    string path= "/home/joao/Documents/c++/T02_G11/Maze/MAZE_XX_WINNERS.TXT";
    path[43] = (char)(maze/10+'0');
    path[44] = (char)(maze%10+'0');
    string line;

    streampos begin, end;
    ofstream win(path);
    begin = win.tellp();
    cout << win.tellp();

/**
    win << setw(16) << name;
    win << time;
    win.close();
    */
}


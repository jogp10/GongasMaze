//T02_G11

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void winner(int name,int time,int maze){
    string path= "/home/joao/Documents/c++/T02_G11/Maze/MAZE_XX_WINNERS.TXT";
    path[43] = (char)(maze/10+'0');
    path[44] = (char)(maze%10+'0');
    string line;

    fstream win(path);  // open file to read and write
    win.seekp(0, ios::end);  // starting point at the end of file
    win << left << setw(15) << name;  // size of name component
    win << internal << setw(8) << time << '\n';
    win.close();
}


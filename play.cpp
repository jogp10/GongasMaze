//T02_G11

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void winner(string name,int time,int maze){
    char* file= "MAZE_XX_WINNERS.TXT";
    file[5] = maze/10;
    file[6] = maze%10;


}


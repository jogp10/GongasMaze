//T02_G11

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "game.h"

using namespace std;

int menu();

int main(){
    int menu_choice;  // menu option

    while(true) {
        // Iniciate Menu
        menu_choice = menu();

        switch (menu_choice) {
            case 1:     // Rules of the game
                ReadRules();
                cout << endl;
                break;

            case 2:    // Start the game
                play();
                cout << endl;
                break;

            case 3:    // Leaderboard
                //leaderboard();
                cout << endl;
                break;

            default:  // Exit the game
                this_thread::sleep_for(chrono::seconds(2));
                return 0;
        }
    }
}
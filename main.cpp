//T02_G11

#include "jogo.h"
#include <iostream>
#include <thread>
#include <chrono>


int main(){
    int menu_choice;  // menu option

    while(true) {
        // Initiate Menu
        if(cin.eof()) menu_choice = 0;
        else menu_choice = menu();

        switch (menu_choice) {
            case 1:     // Rules of the game
                ReadRules();
                std::cout << endl;
                break;

            case 2:    // Start the game
                play();
                std::cout << endl;
                break;

            case 3:    // Leaderboard
                leaderboard();
                std::cout << endl;
                break;

            default:  // Exit the game
                this_thread::sleep_for(chrono::seconds(2));
                return 0;
        }
    }
}

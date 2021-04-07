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


int main(){
    int menu_choice;  // menu option
    bool play_again;

Menu:  // label
    // Iniciate Menu
    menu_choice = menu();

    switch(menu_choice)
    {
        case 1:     // Rules of the game
            ReadRules();
            goto Menu;

        case 2:    // Start the game
            play_again = play();
            if(play_again)
            {
                goto Menu;
            }
            break;

        default:  // Exit the game
            this_thread::sleep_for(chrono::seconds(2));
            break;
    }

    return 0;
}
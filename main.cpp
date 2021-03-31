//T02_G11

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
Start of the game
Let's play
 */
void play();

int main() {
    int menu_choice;
    int goBack;
    string line;
    ifstream myfile ("/home/joao/Documents/c++/T02_G11/rules.txt");

    // Main Menu
    cout << "1) Rules" << endl;
    cout << "2) Play" << endl;
    cout << "0) Exit" << endl;
    cin >> menu_choice;

    // If the menu_choice is not valid
    while(cin.fail() || (menu_choice!=0 && menu_choice !=1 && menu_choice != 2)){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input a valid operation!" << endl;
        cin >> menu_choice;
    }

    switch(menu_choice)
    {
        case 0:     //Exit Game
            break;

        case 1:     // Rules of the game
            while ( getline (myfile,line) )
            {
                cout << line << '\n';
            }
            cout << "Press 0 to go to the main menu" << endl;
            cin >> goBack;
            while(goBack != 0) cin >> goBack;
            return main();

        case 2:    // Start the game
            play();
            break;
    }

    return 0;
}

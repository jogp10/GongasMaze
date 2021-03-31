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
    int choice;
    int goBack;
    string line;
    ifstream myfile ("/home/joao/Documents/c++/T02_G11/rules.txt");

    // Main Menu
    cout << "1) Rules" << endl;
    cout << "2) Play" << endl;
    cout << "0) Exit" << endl;
    cin >> choice;

    // If the choice is not an integer
    if(cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input a valid operation!" << endl;
        return main();
    }

    switch(choice)
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
            if(goBack == 0) return main();
            break;

        case 2:    // Start the game
            play();
            break;
        default:  // If the choice is neither 0, 1 or 2
            cout << "Invalid choice! Please choose between 0, 1 and 2!" << endl;
            return main();
    }

    return 0;
}

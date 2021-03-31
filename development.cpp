//T02_G11

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

    void rules(){
        string line;
        ifstream myfile ("/home/joao/Documents/c++/T02_G11/README.txt");

        while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }
        myfile.close();

    }

void menu(){
    int choice;

    cout << "1) Rules" << endl;
    cout << "2) Play" << endl;
    cout << "0) Exit" << endl;
    cin >> choice;

    switch(choice)
    {
        case 0:     //Exit Game
            break;

        case 1:     // Rules of the game
            string line;
            ifstream myfile ("/home/joao/Documents/c++/T02_G11/README.txt");

            while ( getline (myfile,line) )
            {
                cout << line << '\n';
            }
            break;

        case 2:    // Start the game
            //play();
            break;
        default:
            cout << "Invalid choice! Please choose between 0, 1 and 2!" << endl;
            return menu();
    }

}
//T02_G11

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>


using namespace std;

int menu(){
    int menu_choice;

    // Main Menu
    cout << "1) Rules" << endl;
    cout << "2) Play" << endl;
    cout << "0) Exit" << endl;
    cout << "Option: " ; cin >> menu_choice;

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


void print(vector <string> vec){
    int i; 

    //displaying maze to user using elements stored in vec
    for (i=0; i < vec.size(); i++)
    {
        cout << vec.at(i) << endl;
    }
}


void ReadMaze(int n){ 
    int i=0; 

    string path = "Maze/MAZE_xx.txt";
    //replacing 'xx' with the number of maze 
    path[10]= (char)(n/10 + '0');
    path[11]= (char)(n%10 + '0'); 
    string line; //variable where we store individual lines
    vector <string> vec; //place where we will be storing all the lines

    ifstream file(path); //open file

    //insert in vector
    while (getline(file, line))
    {   
        //to ignore maze dimensions
        if (i==0){           
            vec.push_back(" "); 
            i++;
        }
        //add line to vector
        else{
            vec.push_back(line);
        }   
    } 
    print(vec); //call function print
}

void DisplayMaze(int n)
{
    int i=0; 
    string path = "Maze/MAZE_xx.txt";
    //replacing 'xx' with the number of maze 
    path[10]= (char)(n/10 + '0');
    path[11]= (char)(n%10 + '0'); 
    string line; //variable where we store individual lines

    ifstream file(path) ; 

    while (getline(file, line))
    {
        if (i==0){
            cout << setw(9) << "(" << n << ")" << endl; 
            i++;
        }
        else{
            cout << line << endl; 
        }
    }
}

void play(){
    int MazeSelect; char start; 

    DisplayMaze(1); 
    DisplayMaze(2); 
    
    cout << "What Maze do you like the most?" << endl; cin >> MazeSelect; 
    cout << endl << "Good choice, let's start!" << endl << "Enter S when you are READY..." << endl; 
    cin >> start; 

    while (start != 'S' && start != 's')
    {
        cin >> start; 
    }
    
    ReadMaze(MazeSelect); 
    cout << "Done!" << endl;
}


bool order(string a, string b) {return (stoi (a.substr(16, 8), nullptr) < stoi (b.substr(16, 8), nullptr));}


void winner(string name,int time,int maze){
    string path= "Maze/MAZE_XX_WINNERS.TXT";   // path of file to write winners

    //Which maze, change path
    path[10] = (char)(maze/10+'0');
    path[11] = (char)(maze%10+'0');

    // open file to write win
    fstream win(path);

    if (win.is_open()) {
        win.seekp(0, ios::end);  // starting point at the end of file
        win << left << setw(15) << name;  // size of name component
        win << internal << setw(8) << time << '\n';
        win.close();
    }

    // write all lines in a vector
    ifstream readf(path);
    vector<string> file;
    string line;

    if(readf.is_open()) {
        while (getline(readf, line)) {
            file.push_back(line);
        }
        readf.close();
    }

    //sort the vector
    if(file.size()>5) {
        sort(file.begin() + 4, file.end()-1, order);
    }

    // write back into the file
    ofstream writef(path);  // open file to read and write

    if (writef.is_open()) {
        for(int i=0; i<=file.size()-1; i++){
            writef << file[i] << endl;
        }
        int j = file.size();
        writef << file[j];
        writef.close();
    }
}
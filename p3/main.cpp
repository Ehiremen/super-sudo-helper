//
// Created by: Ehiremen Ekore on 9/11/2019.
// File name:  main.cpp
//

#include "Game.hpp"

//Post: creates a line of '*'s
void newTestBreak(){
    cout << endl << setw(60) << setfill('*') << " " << endl;
}

string getFileName();
void unitTestState();
void unitTestSquare();

//------------------------------------------------------------------------------

int main(){
    banner();
    string gameFile = getFileName();
    Game gb(gameFile);
    gb.run();
    bye();

    return 0;
}

//------------------------------------------------------------------------------

//unit test for State class
void unitTestState(){
    cout << "State initialized with '-'" << endl;
    State st1('-');
    cout << st1;
    st1.mark('2');
    st1.mark('8');
    st1.mark('8');
    cout << endl << "CHECKING FINAL VALUE" << endl;
    cout << st1;

    newTestBreak();
    cout << "State initialized with null constructor" << endl;
    State st2;
    cout << st2;
    st2.mark('-');
    st2.mark(' ');
    st2.mark('a');
    st2.mark('0');
    st2.mark('6');
    cout << endl << "CHECKING FINAL VALUE" << endl;
    cout << st2;

    newTestBreak();
    cout << "State initialized with fixed value '3'" << endl;
    State st3('3');
    cout << st3;
    st3.mark('5');
    st3.mark('k');
    cout << endl << "CHECKING FINAL VALUE" << endl;
    cout << st3;

    newTestBreak();
    cout << "State initialized with a invalid value" << endl;
    State st4('k');
    cout << st4;

    newTestBreak();
    cout << "Testing a non-uniform possibility list" << endl;
    State st5;
    st5.setSpecialPossibilities(0x23e);
    cout << st5;
    st5.mark('8');
    cout << st5;
    st5.mark('2');
    cout << endl << "CHECKING FINAL VALUE" << endl;
    cout << st5;
}

//------------------------------------------------------------------------------

//unit test for Square class
void unitTestSquare(){
    newTestBreak();
    cout << "Trying to create square at [2, 3] with value '-' (should pass)" << endl;
    Square sq1('-', 2, 3);
    cout << sq1;
    cout << "Trying to mark the square (currently unmarked; should pass)" << endl;
    sq1.mark('3');
    cout << sq1;
    cout << "Trying to mark a marked square (should fail)" << endl;
    sq1.mark('7');
    cout << sq1;

    newTestBreak();
    cout << "Trying to create square with invalid character (should fail)" << endl;
    Square sq2('k', 3, 3);
    cout << sq2;

    newTestBreak();
    cout << "Trying to create square at invalid row/column (should fail)" << endl;
    Square sq3('2', 7, 15);
    cout << sq3;

    newTestBreak();
    cout << "Trying to create square with null constructor (should pass)" << endl;
    Square sq4;
    cout << sq4;
    cout << "Trying to mark the square with invalid character (should fail)" << endl;
    sq4.mark('q');
    cout << sq4;
    cout << "Trying to do a valid mark (should pass)" << endl;
    sq4.mark('8');
    cout << sq4;

    newTestBreak();
    cout << "Making a square with null constructor, changing poslist (for special case)"
         << endl << "Then trying to mark 8 (should fail because not in poslist)"
         << endl << "Then trying to mark 3 (should pass)" << endl;
    Square sq5;
    sq5.setSpecialPossibilities(0x23e);
    cout << sq5;
    sq5.mark('8');
    cout << sq5;
    sq5.mark('3');
    cout << sq5;
    newTestBreak();
}

//------------------------------------------------------------------------------
//Pre:
//Post: The filename the user inputs is returned to the caller UNVALIDATED
string getFileName(){
    string inputFileName;
    cout << "Please input the name of your file, including the extension" << endl;
    cout << "If the file is not in the same folder as this program's executable\n"
            "--or if you're not sure--you are free to"
            " use an explicit file name" << endl;

    getline(cin, inputFileName);

    return inputFileName;
}
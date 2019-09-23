//
// Created by: Ehiremen Ekore on 9/4/2019.
// File name:  main.cpp
//

#include "State.hpp"

void newTestBreak(){
    //creates a line of '*' to separate different tests
    cout << endl << setw(60) << setfill('*') << " " << endl;
}

//------------------------------------------------------------------------------

void unitTestState(){
    //unit test for State class
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

void unitTestSquare(){
    //unit test for Square class
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


int main(){
    banner();
    unitTestState();
    unitTestSquare();
    bye();

    return 0;
}
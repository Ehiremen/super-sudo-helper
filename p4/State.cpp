//
// Created by: Ehiremen Ekore on 9/20/2019.
// File name:  State.cpp
//


/*
 * CHANGES FROM P1:
 *      1. Added a new class: Square
 *      2. Added a getValue() function to State to return the char in it
 */

#include "State.hpp"

//------------------------------------------------------------------------------
State::State(char ch){
    //first check that the value is either '-' or between 1 and 9
    if((ch != '-') && ( ((ch-'0')<1) || ((ch-'0')>9)) ) {
        cerr << "Error: invalid value entered" << endl;
        cerr << "State not properly initialized" << endl;
        value = BAD_VALUE;
    }
    else {
        value = ch;
        if (isdigit(value)) {//i.e. if the ch used is a digit
            possibilities = 0;
            fixed = true;
        }
    }
}

void State::mark(char ch){
    //to set the value of a State
    if(fixed){ //trying to change a fixed state
        cout << "Error: state is fixed" << endl;
    }
    else if(((ch-'0')<1)||((ch-'0')>9)){//if ch is not between 1 and 9
        cout << "Error: can only mark valid digits" << endl;
    }
    else{
        // all code before the next else{} checks to make sure I'm not trying to
        // mark an impossible value
        int valueInt = ch - '0';
        bool validMarkVal = (possibilities>>valueInt) & 1;
        if(!validMarkVal){//ch is not a possibility
            cout << "Error: '" << ch << "' is not a valid possibility" << endl;
        }
        else {
            value = ch;
            possibilities = 0;
        }
    }
}
ostream& State:: print(ostream& out){
    //prints important State data
    string tempOut;
    out << "Current value: " << value << " " << "Possibilities: ";
    for (int k=9; k>0; k--){
        int shiftVal = (possibilities>>k) & 1;
        if(shiftVal == 0){//not fixed
            out << right << "" << '-' << "  ";
        }
        else{
            out << right << "" << k << "  ";
        }
    }
    out << endl;
    return out;
}

void State:: setSpecialPossibilities(short shrt){
    //function to allow for testing special test cases
    possibilities = shrt;
    fixed = false;
    value = '-';
}

//------------------------------------------------------------------------------

Square::Square(char ch, short row, short col) : st(ch){
    if ((1 <= row) && (row <= 9) && (1 <= col) && (col <= 9)) {
        //first check that row and col are valid numbers
        if (st.getValue() == BAD_VALUE){
            //also, was State successfully initialized?
            cerr << "Square not properly initialized" << endl;
        }
        else {
            rowNumber = row;
            columnNumber = col;
            cerr << "Square " << row << ", " << col << " constructed." << endl;
        }
    }
    else {
        st = State(BAD_VALUE);
        //sets the state to a bad state so we know the square is invalid
        cerr << "Square not properly initialized" << endl;
    }
}

ostream& Square:: print(ostream& out){
    //to print relevant Square data
    out << "Square [" << rowNumber << ", " << columnNumber << "] " << st;
    return out;
}
//
// Created by: Ehiremen Ekore on 9/2/2019.
// File name:  State.cpp
//

#include "State.hpp"
//------------------------------------------------------------------------------
State::State() = default;
State::State(char ch){
    //first check that the value is either '-' or between 1 and 9
    if((ch != '-') && ( ((ch-'0')<1) || ((ch-'0')>9)) ) {
        cerr << "Error: invalid value entered" << endl;
        cerr << "State not properly initialized" << endl;
        value = EMPTY_VALUE;
    }
    else {
        value = ch;
        if (isdigit(value) != 0) {//i.e. if the ch used is a digit
            possibilities = 0;
            fixed = true;
        }
    }
}
State::~State() = default;

void State::mark(char ch){
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
        int validMarkVal = (possibilities>>valueInt)%2;
        if(validMarkVal == 0){//ch is not a possibility
            cout << "Error: '" << ch << "' is not a valid possibility" << endl;
        }
        else {
            value = ch;
            possibilities = 0;
            fixed = true;
        }
    }
}
char State::getValue() {return value;}
ostream& State:: print(ostream& out){
    string tempOut;
    char arr[10];
    out << "Current value: " << value << " " << "Possibilities: ";
    for (int k=9; k>0; k--){
        int shiftVal = (possibilities>>k)%2;
        if(shiftVal == 0){//not fixed
            arr[k] = '-';
            tempOut += '-';
        }
        else{
            arr[k] = '0' + shiftVal;
            tempOut += to_string(k);
        }
        //hiding the '1', '-' representation of possibilities
        //out << arr[k];
    }
    out << right << "" << tempOut << endl;
    return out;
}

//function to allow for testing special test cases
void State:: setSpecialPossibilities(short sht){
    possibilities = sht;
    fixed = false;
    value = '-';
}
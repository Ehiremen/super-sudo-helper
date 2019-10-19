//
// Created by: Ehiremen Ekore on 9/02/2019.
// Modified by: Ehiremen Ekore on 9/27/2019.
// File name:  State.cpp
//

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
        if (isdigit(value)) { possibilities = 0;}
    }
}
//------------------------------------------------------------------------------

//to set the value of a State
void State::mark(char ch){
    if(ch-'0' > 9 || ch==0){ cout << "Error: can only mark digits from 1 to 9" << endl;}
    else{
        int valueInt = ch - '0';
        bool validMarkVal = (possibilities>>valueInt) & 1;
        //is valueInt a valid possibility?
        if(!validMarkVal){ cout << "Error: '" << ch << "' is not a valid possibility" << endl;}
        else {
            value = ch;
            possibilities = 0;
        }
    }
}
//------------------------------------------------------------------------------

ostream& State:: print(ostream& out){
    //prints important State data
    string tempOut;
    out << "Current value: " << value << " " << "Possibilities: ";
    for (int k=9; k>0; k--){
        bool possibleVal = (possibilities >> k) & 1;
        if(possibleVal){ out << right << "" << k << "  ";}
        else{ out << right << "" << '-' << "  ";}
    }
    out << endl;
    return out;
}
//------------------------------------------------------------------------------

void State::turnOff(int n) {
    short setToZero = 1<<n;
    if(possibilities>>n & 1) { //is n still possible?
        possibilities -= setToZero;
    }
}
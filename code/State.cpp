//
// Created by: Ehiremen Ekore on 9/02/2019.
// Modified by: Ehiremen Ekore on 11/15/2019.
// File name:  State.cpp
//

#include "State.hpp"
#include "Frame.hpp"

State::State(char ch, int posLen) : numPos(posLen){
    legalValues = string(allLegalVal.begin(), allLegalVal.begin() + posLen + 1);
                //assign the set of legal values based on board size (posLen)
    
    if (posLen == 6) possibilities = 0x7e; // replace 9, 8, and 7 with 0 if sixy puzzle

    size_t valid = legalValues.find(ch);
    
    //first check that the value is either '-' or between 1 and posLen (6 or 9)
    if(valid == string::npos){ value = BAD_VALUE; }
    else {
        value = ch;
        if (isdigit(value)) { possibilities = 0;}
    }
}
//------------------------------------------------------------------------------

//to set the value of a State
void State::mark(char ch){
    size_t valid = legalValues.find(ch);
    if(valid == string::npos){ throw BadPos(ch, getPos(), numPos);}
    else{
        int valueInt = ch - '0';
        bool validMarkVal = (possibilities>>valueInt) & 1;
        if(!validMarkVal){ throw BadPos(ch, getPos(), numPos);}
        else { value = ch; possibilities = 0; }
    }
}
//------------------------------------------------------------------------------

// Prints important state data
ostream& State:: print(ostream& out){
    out << "Current value: " << value << " " << "Possibilities: ";
    for (int k=numPos; k>0; k--){
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
    if(n<1 || n>numPos){ throw BadPos((n+'0'), getPos(), numPos);}
    
    // is n still possible?
    if(possibilities>>n & 1) {
        possibilities -= setToZero;
    }
}

//
// Created by: Ehiremen Ekore on 9/02/2019.
// Modified by: Ehiremen Ekore on 12/11/2019.
// File name:  State.hpp
//

#pragma once

#include "tools.hpp"
#include "BadLogic.hpp"
#include "BadGameFile.hpp"

#define BAD_VALUE '@'
class FrameHelper;
static const string allLegalVal = "-123456789"; //union of chars allowed for sixy and trad squares

class State{
private:
    short possibilities = 0x3fe;
    char value = '-';
    int numPos; //number of valid possibilities
    string legalValues; //set of allowed chars depending on numPos

    void helpRealize ( char val, short pos, int posLen) {
        value = val;
        possibilities = pos;
        numPos = posLen;
    }
    friend FrameHelper;

public:
    State() = default;
    State(char ch, int posLen);
    ~State() = default;
    State(const State &s2) {    //copy constructor
        value = s2.getValue(); possibilities = s2.getPos(); numPos = s2.getNumPos();
    }

    ostream& print(ostream& out);
    void mark(char ch);
    void turnOff(int n);
    char getValue() const {return value;}
    short getPos() const {return possibilities;}
    int getNumPos() const { return  numPos;}
};

inline ostream& operator << (ostream& out, State& st){
    return st.print(out);
}

class FrameHelper{
protected:
    void helpRealize ( State& st, char val, short pos, int posLen) { st.helpRealize(val, pos, posLen);}
};

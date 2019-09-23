//
// Created by ehise on 9/2/2019.
//

#pragma once

#include "tools.hpp"
#define EMPTY_VALUE '@'

class State{
private:
    short possibilities = 0x3fe;
    char value = '-';
    bool fixed = false;

public:
    State();
    State(char ch);
    ~State();

    void mark(char ch);
    ostream& print(ostream& out);

    //function to allow for testing special test cases
    void setSpecialPossibilities(short sht);
    char getValue() {return value;}
};

//errors come when I declare it as inline but define in State.cpp
inline ostream& operator << (ostream & out, State st){
    return st.print(out);
}
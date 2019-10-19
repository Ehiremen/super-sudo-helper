//
// Created by: Ehiremen Ekore on 9/02/2019.
// Modified by: Ehiremen Ekore on 9/27/2019.
// File name:  State.hpp
//

/*
 * CHANGES FROM P4:
 *      1. Moved Square to its own cpp file
 *      2. Removed State::setSpecialPossibilities(short sht)
 *      3. Added a turnOff(int n) function to help modify poslist when shooping
 */

#pragma once

#include "tools.hpp"

#define BAD_VALUE '@'
class State{
private:
    short possibilities = 0x3fe;
    char value = '-';

public:
    State() = default;
    State(char ch);
    ~State() = default;

    ostream& print(ostream& out);
    void mark(char ch);
    char getValue(){return value;}
    void turnOff(int n);
};
inline ostream& operator << (ostream & out, State& st){
    return st.print(out);
}
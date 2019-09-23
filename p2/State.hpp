//
// Created by: Ehiremen Ekore on 9/4/2019.
// File name:  State.hpp
//

#pragma once

#include "tools.hpp"

#define BAD_VALUE '@'
#define NO_ROW 0x0
#define NO_COLUMN 0x0

class State{
private:
    short possibilities = 0x3fe;
    char value = '-';
    bool fixed = false;

public:
    State() = default;
    State(char ch);
    ~State() = default;

    void mark(char ch);
    char getValue(){return value;}
    ostream& print(ostream& out);

    //function to allow for testing special test cases
    void setSpecialPossibilities(short sht);
};
inline ostream& operator << (ostream & out, State st){
    return st.print(out);
}

//------------------------------------------------------------------------------

class Square{
private:
    State st;
    short rowNumber=NO_ROW, columnNumber=NO_COLUMN;

public:
    Square() = default;
    Square(char ch, short row, short col);
    ~Square() {
        cerr <<"Deleting square " << rowNumber << ", " << columnNumber << endl;
    }

    void mark(char ch){
        st.mark(ch);
    }

    void setSpecialPossibilities(short sht){
        //function to allow me change pos_list for Square
        //just for testing purposes
        st.setSpecialPossibilities(sht);
    }
    ostream& print(ostream& out);
};
inline ostream& operator << (ostream & out, Square sq){
    return sq.print(out);
}
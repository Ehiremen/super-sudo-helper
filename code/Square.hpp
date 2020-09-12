//
// Created by:  Ehiremen Ekore on 9/27/2019.
// Modified by: Ehiremen Ekore on 12/11/2019.
// File name:   Square.hpp
//

#pragma once

#include "State.hpp"

#define NO_ROW 0
#define NO_COLUMN 0

class Cluster;
class HelperBoard;

class Square{
private:
    State st;
    int maxPos;
    short rowNumber=NO_ROW, columnNumber=NO_COLUMN;
    vector<Cluster*>myClusters;
    void setState(State newState) { st = newState;}
    friend HelperBoard;

public:
    Square() = default;
    Square(char ch, short row, short col, int numPos);
    ~Square();

    void mark(char ch){ st.mark(ch);}
    char getValue(){ return st.getValue();}
    bool validSquare(int row, int col);
    ostream& print(ostream& out);

    void addCluster(Cluster* cl){ myClusters.push_back(cl);}
    void shoop(char val);
    void turnOff(int n){ st.turnOff(n);}
    string poslistString() const;
    short getPos() const {return st.getPos();}
    State getState() { return st;}
};

inline ostream& operator << (ostream & out, Square& sq){
    return sq.print(out);
}

class HelperBoard{
protected:
    void setState(Square& sq, State newState) { sq.setState(newState);}
};

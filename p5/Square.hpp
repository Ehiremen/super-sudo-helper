//
// Created by: Ehiremen Ekore on 9/27/2019.
// File name:  Square.hpp
//

/*
 * CHANGES FROM P4:
 *      1. Moved Square to its own cpp file
 *      2. Removed Square::setSpecialPossibilities(short sht)
 *      3. Added a private vector of Cluster* to Square's members
 *      4. Added a getValue() function
 *      5. Added an addCluster(Cluster* cl) function
 *      6. Added a shoop(char val) function
 *      7. Added a turnOff(int n) function
 */

#pragma once

#include "State.hpp"

#define NO_ROW 0
#define NO_COLUMN 0

class Cluster;
class Square{
private:
    State st;
    short rowNumber=NO_ROW, columnNumber=NO_COLUMN;
    vector<Cluster*>myClusters;

public:
    Square() = default;
    Square(char ch, short row, short col);
    ~Square();

    void mark(char ch){ st.mark(ch);}
    char getValue(){ return st.getValue();}
    ostream& print(ostream& out);

    void addCluster(Cluster* cl){ myClusters.push_back(cl);}
    void shoop(char val);
    void turnOff(int n){ st.turnOff(n);}
};
inline ostream& operator << (ostream & out, Square& sq){
    return sq.print(out);
}
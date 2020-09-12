//
// Created by:  Ehiremen Ekore on 9/27/2019.
// Modified by: Ehiremen Ekore on 12/11/2019.
// File name:   Square.cpp
//

#include "Square.hpp"
#include "Cluster.hpp"
//------------------------------------------------------------------------------

Square::Square(char ch, short row, short col, int numPos): maxPos(numPos) {
    try {
        st =  State(ch, maxPos);
    }
    catch (BadGameData& bad) {bad.print(); exit(1);}

    if (!validSquare(row, col)) { //are row and col valid numbers?
        st = State(BAD_VALUE, maxPos);
        throw BadSquare(row, col, maxPos);
    }
    else {
        if (st.getValue() == BAD_VALUE){
            throw BadSquareInit(row, col, maxPos);
        }
        else {
            rowNumber = row;
            columnNumber = col;
            cerr << "Square " << row << ", " << col << " constructed." << endl;
        }
    }
}
//------------------------------------------------------------------------------

Square:: ~Square() {
    cerr <<"Deleting square " << rowNumber << ", " << columnNumber << endl;
}
//------------------------------------------------------------------------------

bool Square::validSquare(int row, int col){
    bool valid = false;
    if (row>0 && row<10){
        if(col>0 && col<10){
            valid = true;
        }
    }
    return valid;
}
//------------------------------------------------------------------------------

ostream& Square:: print(ostream& out){
    out << "Square [" << rowNumber << ", " << columnNumber << "] " << st;
    return out;
}
//------------------------------------------------------------------------------

//Pre:  val is marked in Square A, but might still seen as a valid possibility
//      in the poslist of another Square B in the same cluster as Square A
//Post: val has been removed from all Clusters of Square A
void Square:: shoop(char val){
    for(Cluster* cluster: myClusters){ cluster->shoop(val);}
}
//------------------------------------------------------------------------------

//returns the poslist in a string containing '-' or possible numbers
//e.g. "--3456789"
string Square::poslistString() const {
    string posString;
    short posList = st.getPos();
    for (int k=9; k>0; k--){
        bool possibleVal = (posList >> k) & 1;
        posString += (possibleVal ? (char) ('0' + k) : '-');
    }
    return posString;
}